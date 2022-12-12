/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:30:09 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/12 21:30:21 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	ft_back_redir(int *fd)
{
	if (fd[0] != -1)
	{
		if (dup2(STDIN_FILENO, fd[0]) == -1)
			perror("redirections");
		close(fd[0]);
		fd[0] = -1;
	}
	if (fd[1] != -1)
	{
		if (dup2(STDOUT_FILENO, fd[1]) == -1)
			perror("redirections");
		close(fd[1]);
		fd[1] = -1;
	}
}
