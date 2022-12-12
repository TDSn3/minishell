/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:40:40 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/12 17:17:36 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	print_error(char *cmd, int nb_error);
static int	part_two(t_node *node, t_input *input, size_t size_argv);
static int	part_three(t_node *node, t_input *input);

int	builtin_chr(t_node *node, t_input *input)
{
	size_t	size_argv;

	if (!node->args || !node->args[0])
		return (1);
	ms_redir(input, node);
	size_argv = my_strdlen(node->args);
	if (!my_strcmp(node->args[0], "env"))
	{
		if (size_argv > 1)
			print_error(node->args[0], -1);
		else
			ms_env(input);
		return (1);
	}
	if (!my_strcmp(node->args[0], "pwd"))
	{
		if (size_argv > 1)
			print_error(node->args[0], -1);
		else
			ms_pwd();
		return (1);
	}
	return (part_two(node, input, size_argv));
}

static int	part_two(t_node *node, t_input *input, size_t size_argv)
{
	int		i;

	i = 1;
	if (!my_strcmp(node->args[0], "cd"))
	{
		if (size_argv > 2)
			print_error(node->args[0], -1);
		else
			ms_cd(node->args[1], input);
		return (1);
	}
	if (!my_strcmp(node->args[0], "export"))
	{
		if (node->args[1])
			while (node->args[i])
				ms_export(node->args[i++], input);
		if (!node->args[1])
			ms_export(NULL, input);
		return (1);
	}
	return (part_three(node, input));
}

static int	part_three(t_node *node, t_input *input)
{
	int		i;

	i = 1;
	if (!my_strcmp(node->args[0], "unset"))
	{
		if (node->args[1])
			while (node->args[i])
				ms_unset(node->args[i++], input);
		return (1);
	}
	if (!my_strcmp(node->args[0], "echo"))
	{
		ms_echo(node->args);
		return (1);
	}
	if (!my_strcmp(node->args[0], "exit"))
	{
		ms_exit(input, 0);
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
	return (1);
}
