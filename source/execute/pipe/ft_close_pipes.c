/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:45:45 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/31 12:02:49 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   STDIN_FILENO  : entrée standard (généralement fd = 0)					  */
/*   STDOUT_FILENO : sortie standard (généralement fd = 1)					  */
/*                                                                            */
/*   Close les fd s'ils ne sont pas stdin ou stdout.						  */
/*                                                                            */
/* ************************************************************************** */
void	ft_close_pipes(int fd[2])
{
	if (fd[1] != STDOUT_FILENO)
		close(fd[1]);
	if (fd[0] != STDIN_FILENO)
		close(fd[0]);
}
