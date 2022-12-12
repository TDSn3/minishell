/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:40:40 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/12 15:48:03 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	print_error(char *cmd, int nb_error);
static int	part_two(char **argv, t_input *input, size_t size_argv);
static int	part_three(char **argv, t_input *input);

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
	return (part_two(node->args, input, size_argv));
}

static int	part_two(char **argv, t_input *input, size_t size_argv)
{
	int		i;

	i = 1;
	if (!my_strcmp(argv[0], "cd"))
	{
		if (size_argv > 2)
			print_error(argv[0], -1);
		else
			ms_cd(argv[1], input);
		return (1);
	}
	if (!my_strcmp(argv[0], "export"))
	{
		if (argv[1])
			while (argv[i])
				ms_export(argv[i++], input);
		if (!argv[1])
			ms_export(NULL, input);
		return (1);
	}
	return (part_three(argv, input));
}

static int	part_three(char **argv, t_input *input)
{
	int		i;

	i = 1;
	if (!my_strcmp(argv[0], "unset"))
	{
		if (argv[1])
			while (argv[i])
				ms_unset(argv[i++], input);
		return (1);
	}
	if (!my_strcmp(argv[0], "echo"))
	{
		ms_echo(argv);
		return (1);
	}
	if (!my_strcmp(argv[0], "exit"))
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
