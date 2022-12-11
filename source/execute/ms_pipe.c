/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:08:00 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/11 21:42:50 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int exit_cmd;

static size_t	ft_strlen2(const char *s)
{
	size_t	count;

	count = 0;
	if (!s || s[count] == '\0')
		return (0);
	while (s[count])
		count++;
	return (count);
}

static char	*ft_strjoin2(char *s1, char const *s2)
{
	size_t	count;
	size_t	copy;
	size_t	len;
	char	*all;

	count = 0;
	copy = 0;
	len = ft_strlen2(s1);
	if (!s1 && !s2)
		return (NULL);
	all = (char *) ft_calloc(len + ft_strlen2(s2) + 1, sizeof(char));
	if (!all)
		return (NULL);
	while (count < len)
		all[copy++] = s1[count++];
	count = 0;
	while (count < ft_strlen2(s2))
		all[copy++] = s2[count++];
	all[copy] = '\0';
	if (len > 0)
		free(s1);
	return (all);
}

static int  execute(t_input *input, t_list *cmds)
{
    int count;
    char    *command;
    t_node  *node;

    count = 0;
    node = cmds->content;
	ms_redir(input, cmds);
    if (!node->args || !node->args[0])
        return (0);
    while (input->paths[count])
    {
        command = ft_strjoin(input->paths[count++], "/");
        command = ft_strjoin2(command, node->args[0]);
        if (access(command, F_OK | X_OK) == 0)
        {
            if (execve(command, node->args, NULL) == -1)
	    {
		free(command);
                return (ft_cmd_error(input, NULL, node->args[0]));
	    }
        }
    }
    if (access(command, F_OK) != 0)
        return (ft_cmd_error(input, NULL, node->args[0]));
    free(command);
    return (1);
}

static void exec_cmd(t_input *input, t_list *cmds)
{
    int pid;
    int status;
	t_node	*node;

	node = cmds->content;
	if (!builtin_chr(node->args, input))
	{
		printf("exit_status = %d\n", g_status);
		return ;
	}
	printf("OK\n");
    pid = fork();
    if (pid < 0)
    {
        ft_cmd_error(input, NULL, "fork");
		free_all(input);
		free_input(input);
        return ;
    }
    if (pid == 0) //fiston
    {
		execute(input, cmds);
		free_all(input);
		free_input(input);
        exit(1);
    }
    else
    {
        wait(&status);          // papa
        if (WIFEXITED(status))
            exit_cmd = WEXITSTATUS(status);

		if (WCOREDUMP(status))
			printf("Quit (core dumped)\n");
		if (WEXITSTATUS(status) == 1)
			g_status = 1;
		else if (WIFSIGNALED(status))
			g_status = WTERMSIG(status) + 128;
		else
			g_status = 0;
		printf("exit_status = %d\n", g_status);
    }
}

static void    create_pipes(t_input *input, t_list *cmds, int *pids, size_t count, int fd[2])
{
    pids[count] = fork();
    if (pids[count] < 0)
    {
        ft_cmd_error(NULL, cmds, "pids");
        return ;
    }
    else if (pids[count] == 0) // papa
    {
        if (fd[0] != 0 && dup2(fd[0], STDIN_FILENO) == -1)
            return;
        if (fd[1] != 1 && dup2(fd[1], STDOUT_FILENO) == -1)
            return;
        exec_cmd(input, cmds);
	free(pids);
	free_input(input);
	free_all(input);
        exit(exit_cmd);
    }
}

static void    wait_pipes(int *pids, size_t size)
{
    size_t    count;
    int    status;
    int    ret;
    int should_stop;

    while (1)
    {
        should_stop = 1;
        count = 0;
        while (count < size)
        {
            if (pids[count] == -1)
            {
                count++;
                continue;
            }
            should_stop = 0;
            ret = waitpid(pids[count], &status, WNOHANG | WUNTRACED);
            if (ret < 0)
            {
                perror("wait");
                continue;
            }
            else if (ret > 0)
            {
                pids[count] = -1;
                if (WIFEXITED(status))
                    exit_cmd = WEXITSTATUS(status);
            }
            count ++;
        }
        if (should_stop)
            return;
    }
}

void    ms_pipe(t_input *input, t_list *cmds, size_t size)
{
    int    *pids;
    size_t    count;
    int in = 0;

    pids = (int *) ft_calloc(ft_lstsize(cmds), sizeof(int));
    if (!pids)
        return ;
    count = 0;
    while (cmds && count < size)
    {
        int    fd[2];

        if (cmds->next && pipe(fd) < 0)
        {
            return ;
        }
        int tmp = fd[0];
        fd[0] = in;
        if (count == size - 1)
            fd[1] = 1;

        create_pipes(input, cmds, pids, count, fd);
        if (fd[1] != STDOUT_FILENO)
            close(fd[1]);
        if (fd[0] != STDIN_FILENO)
            close(fd[0]);
        in = tmp;
        cmds = cmds->next;
        count ++;
    }
    wait_pipes(pids, size);
    free(pids);
}

void    execute_em(t_input *input)
{
    t_list  *cmds;
    size_t  size;

    cmds = input->ast;
    size = ft_lstsize(cmds);
    if (size == 1)
        exec_cmd(input, cmds);
    else if (size > 1)
        ms_pipe(input, cmds, size);
    else
        return ;
}
