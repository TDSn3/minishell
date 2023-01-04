/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:40:40 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/04 17:45:45 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	exec_builtins(t_node *node, t_input *input, int builtin);
static void	exec_builtins_two(t_node *node, t_input *input,
				int builtin, int redir);
static void	part_three(t_node *node, t_input *input, int builtin);
static int	print_error(char *cmd, int nb_error);

int	builtin_chr(t_node *node, t_input *input)
{
	if (!node->args || !node->args[0])
		return (0);
	if (!my_strcmp(node->args[0], "env"))
		exec_builtins(node, input, 1);
	else if (!my_strcmp(node->args[0], "pwd"))
		exec_builtins(node, input, 2);
	else if (!my_strcmp(node->args[0], "cd"))
		exec_builtins(node, input, 3);
	else if (!my_strcmp(node->args[0], "export"))
		exec_builtins(node, input, 4);
	else if (!my_strcmp(node->args[0], "unset"))
		exec_builtins(node, input, 5);
	else if (!my_strcmp(node->args[0], "echo"))
		exec_builtins(node, input, 6);
	else if (!my_strcmp(node->args[0], "exit"))
		exec_builtins(node, input, 7);
	else
		return (0);
	return (1);
}

static void	exec_builtins(t_node *node, t_input *input, int builtin)
{
	size_t	size_argv;
	int		redir;

	redir = -1;
	size_argv = my_strdlen(node->args);
	if (node->redir)
		redir = save_redir(node, input);
	if (builtin == 1 || builtin == 2)
	{
		if (size_argv > 1)
			print_error(node->args[0], -1);
		else if (builtin == 1)
			g_status = ms_env(input);
		else if (builtin == 2)
			g_status = ms_pwd();
	}
	else if (builtin == 3)
	{
		if (size_argv > 2)
			print_error(node->args[0], -1);
		else
			g_status = ft_cd(input, node->args, ft_strdlen(node->args));
	}
	exec_builtins_two(node, input, builtin, redir);
}

static void	exec_builtins_two(t_node *node, t_input *input,
				int builtin, int redir)
{
	int	i;

	i = 1;
	if (builtin == 4)
	{
		if (node->args[1])
			while (node->args[i])
				g_status = ms_export(node->args[i++], input);
		if (!node->args[1])
			g_status = ms_export(NULL, input);
	}
	part_three(node, input, builtin);
	restore_redir(input, redir);
}

static int	print_error(char *cmd, int nb_error)
{
	if (nb_error == -1)
		ft_putstr_fd("too many arguments\n", 2);
	else
	{
		errno = nb_error;
		perror("export");
	}
	g_status = 1;
	(void) cmd;
	return (1);
}

static void	part_three(t_node *node, t_input *input, int builtin)
{
	int		i;

	i = 1;
	if (builtin == 5)
	{
		if (node->args[1])
			while (node->args[i])
				ms_unset(node->args[i++], input);
		g_status = 0;
	}
	if (builtin == 6)
			g_status = ms_echo(node->args);
	if (builtin == 7)
		exit_bultin_util(node, input);
}
