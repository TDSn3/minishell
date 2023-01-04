/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:48:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/04 18:00:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	fork_pipe(t_input *input, t_list *cmd, int *fdin, int i);
static void	pipe_child(t_input *input, t_list *cmd, int fd[2]);

/* ************************************************************************** */
/*                                                                            */
/*   Parcours la liste cmd et exécute toutes les commandes.					  */
/*                                                                            */
/* ************************************************************************** */
void	exec_pipe(t_input *input, t_list *cmd, size_t size)
{
	size_t	i;
	int		fdin;

	i = 0;
	fdin = 0;
	while (cmd && i < size)
	{
		if (!fork_pipe(input, cmd, &fdin, i))
			return ;
		cmd = cmd->next;
		i++;
	}
	wait_pipes(input->pids, size);
}

/* ************************************************************************** */
/*                                                                            */
/*   fd[0] extrémité de lecture					 							  */
/*   fd[1] extrémité d'écriture												  */
/*                                                                            */
/* ************************************************************************** */
static int	fork_pipe(t_input *input, t_list *cmd, int *fdin, int i)
{
	int	fd[2];
	int	tmp;

	fd[0] = 0;
	if (cmd->next && pipe(fd) < 0)
		return (0);
	tmp = fd[0];
	fd[0] = *fdin;
	if (!cmd->next)
		fd[1] = 1;
	input->pids[i] = fork();
	if (input->pids[i] < 0)
		return (ft_cmd_error(cmd, "pids"));
	else if (input->pids[i] == 0)
	{
		close(tmp);
		pipe_child(input, cmd, fd);
	}
	ft_close_pipes(fd);
	*fdin = tmp;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*   Modifie stdin et stdout. Exécute la commande et redirige la sortie		  */
/*   vers la prochaine commande grâce à la modification de stdin et stdout.	  */
/*                                                                            */
/* ************************************************************************** */
static void	pipe_child(t_input *input, t_list *cmd, int fd[2])
{
	ft_link_pipes(&fd[0], 0);
	if (cmd->next)
		ft_link_pipes(&fd[1], 1);
	check_cmd(input, cmd);
	free_input(input);
	free_all(input);
	ft_close_pipes(fd);
	exit(g_status);
}
