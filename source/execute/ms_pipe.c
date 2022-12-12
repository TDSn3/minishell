/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:08:00 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/12 21:20:13 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	create_pipes(t_input *input, t_list *cmds, int *pids, size_t count, int fd[2]);
static void	wait_pipes(int *pids, size_t size);

void	ms_pipe(t_input *input, t_list *cmds, size_t size)
{
	int		*pids;
	size_t	count;
	int		in;

	in = 0;
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

static void	create_pipes(t_input *input, t_list *cmds, int *pids, size_t count, int fd[2])
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
		else if (fd[0] != 0)
			close(fd[0]);
		if (fd[1] != 1 && dup2(fd[1], STDOUT_FILENO) == -1)
			return;
		else if (fd[1] != 1)
			close(fd[1]);
		execute_one_cmd(input, cmds);
		free(pids);
		free_input(input);
		free_all(input);
		close(fd[0]);
		close(fd[1]);
		close(0);
		close(1);
		char str[512];
		snprintf(str, sizeof str, "lsof -p %d", getpid());
		system(str);
		exit(g_status);
	}
}

static void	wait_pipes(int *pids, size_t size)
{
	size_t	count;
	int		status;
	int		ret;
	int		should_stop;

	while (1)
	{
		should_stop = 1;
		count = 0;
		while (count < size)
		{
			if (pids[count] == -1)
			{
				count++;
				continue ;
			}
			should_stop = 0;
			ret = waitpid(pids[count], &status, WNOHANG | WUNTRACED);
			if (ret < 0)
			{
				perror("wait");
				continue ;
			}
			else if (ret > 0)
			{
				pids[count] = -1;
				if (WIFEXITED(status))
					g_status = WEXITSTATUS(status);
			}
			count ++;
		}
		if (should_stop)
			return ;
	}
}

