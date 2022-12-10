/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_em.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:08:00 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/10 15:08:40 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	execute_em(t_input *input)
{
	t_list	*cmds;
	size_t	size;

	cmds = input->ast;
	size = ft_lstsize(cmds);
	if (size  == 1)
		exec_cmd(input, cmds);
	else if (size > 1)
		ft_pipe(input, cmds, size);
}

static int	execute(t_input *input, t_list *cmds)
{
	int	count;
	char	*command;
	t_node	*node;

	count = 0;
	node = cmds->content;
	if (!node->args || !node->args[0])
		return (0);
	while (input->paths[count])
	{
		command = ft_strjoin(input->paths[count++], "/");
		command = ft_strjoin2(command, node->args[0]);
		if (access(command, F_OK | X_OK) == 0)
		{	
			if (execve(command, node->args, NULL) == -1)
				return (ft_cmd_error(input, NULL, node->args[0]));
		}
	}
	if (access(command, F_OK) != 0)
		return (ft_cmd_error(input, NULL, node->args[0]));
	free(command);
	return (1);
}

static void	exec_cmd(t_input *input, t_list *cmds)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid < 0)
	{
		ft_cmd_error(input, NULL, "fork");
		return ;
	}
	if (pid == 0) //fiston
	{
		execute(input, cmds);
		exit(1);
	}
	else
	{
		wait(&status);			// papa
		if (WIFEXITED(status))
			exit_cmd = WEXITSTATUS(status);
	}
}

static void	create_pipes(t_input *input, t_list *cmds, int *pids, int count)
{
	int	fd[2];
	
	if (pipe(fd) < 0)
		return ;
	pids[count] = fork();
	if (pids[count] < 0)
	{
		ft_cmd_error(NULL, cmds, "pids");
		return ;
	}
	else if (pids[count] == 0) // papa
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			return ;
		close(fd[1]);
		exec_cmd(input, cmds);
		exit(exit_cmd);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			return ;
		close(fd[0]);
	}
}

static void	wait_pipes(int *pids, size_t size)
{
	size_t	count;
	int	status;
	int	ret;

	count = 0;
	while (count < size)
	{
		ret = waitpid(pids[count], &status, 0);
		if (ret != 0)
		{
			if (WIFEXITED(status))
				exit_cmd = WEXITSTATUS(status);
		}
		count ++;
	}
}

void	ft_pipe(t_input *input, t_list *cmds, size_t size)
{
	int	*pids;
	size_t	count;
	int	fd[2];

	fd[0] = dup(input->fdin);
	fd[1] = dup(input->fdout);
	pids = (int *) ft_calloc(ft_lstsize(cmds), sizeof(int));
	if (!pids)
		return ;
	count = 0;
	while (cmds && count < size - 1)
	{
		create_pipes(input, cmds, pids, count);
		close(1);
		cmds = cmds->next;
		count ++;
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
		return ;
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return ;
	exec_cmd(input, cmds);
	wait_pipes(pids, size);
}
