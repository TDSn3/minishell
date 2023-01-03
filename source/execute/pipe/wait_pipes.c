/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:46:14 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/03 13:07:11 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	waiting_pipe(int *pids, int count, int status, size_t size);

void	wait_pipes(int *pids, size_t size)
{
	size_t	i;
	int		status;
	int		should_stop;

	status = 0;
	while (1)
	{
		should_stop = 1;
		i = 0;
		while (i < size)
		{
			if (pids[i] == -1)
			{
				i++;
				continue ;
			}
			should_stop = 0;
			if (waiting_pipe(pids, i, status, size) < 0)
				continue ;
			else
				i++;
		}
		if (should_stop)
			return ;
	}
}

static int	waiting_pipe(int *pids, int count, int status, size_t size)
{
	int	ret;

	ret = waitpid(pids[count], &status, WNOHANG | WUNTRACED);
	if (ret < 0)
		perror("wait");
	else if (ret > 0)
	{
		pids[count] = -1;
		if (WIFEXITED(status) && WEXITSTATUS(status) != 141
			&& (size_t)count + 1 >= size)
			g_status = WEXITSTATUS(status);
	}
	return (ret);
}
