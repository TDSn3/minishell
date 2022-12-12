/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:40:40 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/12 21:31:39 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	print_error(char *cmd, int nb_error);
static int	part_two(t_node *node, t_input *input, size_t size_argv, int fd[2]);
static int	part_three(t_node *node, t_input *input, int fd[2]);

int	builtin_chr(t_node *node, t_input *input)
{
	size_t	size_argv;
	int		fd[2];

	if (!node->args || !node->args[0])
		return (1);
	size_argv = my_strdlen(node->args);
	fd[0] = -1;
	fd[1] = -1;
	if (!my_strcmp(node->args[0], "env"))
	{
		if (size_argv > 1)
			print_error(node->args[0], -1);
		else
			g_status = ms_env(input);
		return (1);
	}
	if (!my_strcmp(node->args[0], "pwd"))
	{
		if (size_argv > 1)
			print_error(node->args[0], -1);
		else
			g_status = ms_pwd();
		return (1);
	}
	return (part_two(node, input, size_argv, fd));
}

static int	part_two(t_node *node, t_input *input, size_t size_argv, int fd[2])
{
	int		i;

	i = 1;
	if (!my_strcmp(node->args[0], "cd"))
	{
		ms_redir(input, node);
		if (size_argv > 2)
			print_error(node->args[0], -1);
		else
			g_status = ms_cd(node->args[1], input);
		return (1);
	}
	if (!my_strcmp(node->args[0], "export"))
	{
		ms_redir(input, node);
		if (node->args[1])
			while (node->args[i])
				g_status = ms_export(node->args[i++], input);
		if (!node->args[1])
			g_status = ms_export(NULL, input);
		return (1);
	}
	return (part_three(node, input, fd));
}

static int	part_three(t_node *node, t_input *input, int fd[2])
{
	int	i;

	i = 1;
	if (!my_strcmp(node->args[0], "unset"))
	{
		ms_redir(input, node);
		if (node->args[1])
			while (node->args[i])
				ms_unset(node->args[i++], input);
		g_status = 0;
		return (1);
	}
	if (!my_strcmp(node->args[0], "echo"))
	{
		ft_clone_redir(node->redir, fd);
		ms_redir(input, node);
		g_status = ms_echo(node->args);
		ft_back_redir(fd);
		return (1);
	}
	if (!my_strcmp(node->args[0], "exit"))
	{
		ms_redir(input, node);
		g_status = 0;
		return (1);
	}
	return (0);
}

static int	print_error(char *cmd, int nb_error)
{
	if (nb_error == -1)
		printf("%s: too many arguments\n", cmd);
	else
	{
		errno = nb_error;
		perror("export");
	}
	g_status = 1;
	return (1);
}
