/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:08:00 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/16 16:37:37 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	ft_link_pipes(int *fd, int todup);

static void	ft_link_pipes(int *fd, int todup)
{
	if (*fd != todup && dup2(*fd, todup) == -1)
		return ;
	else if (*fd != todup)
		close(*fd);
}

void	ft_close_pipes(int fd[2])
{
	if (fd[1] != STDOUT_FILENO)
		close(fd[1]);
	if (fd[0] != STDIN_FILENO)
		close(fd[0]);
}

void	pipe_child(t_input *input, t_list *cmds, int fd[2])
{
	ft_link_pipes(&fd[0], 0);
	if (cmds->next)
		ft_link_pipes(&fd[1], 1);
	check_cmd(input, cmds);
	free_input(input);
	free_all(input);
	ft_close_pipes(fd);
	exit(g_status);
}

static int	waiting(int *pids, int count, int status)
{
	int	ret;

	ret = waitpid(pids[count], &status, WNOHANG | WUNTRACED);
	if (ret < 0)
		perror("wait");
	else if (ret > 0)
	{
		pids[count] = -1;
		if (WIFEXITED(status) && WEXITSTATUS(status) != 141)
			g_status = WEXITSTATUS(status);
	}
	return (ret);
}

void	wait_pipes(int *pids, size_t size)
{
	size_t	count;
	int		status;
	int		should_stop;

	status = 0;
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
			if (waiting(pids, count, status) < 0)
				continue ;
			else
				count ++;
		}
		if (should_stop)
			return ;
	}
}
