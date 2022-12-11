/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:40:40 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/11 14:40:10 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	buildtin_chr_suite(char **argv, t_input *input);
static int	print_error(char *cmd, int nb_error);

int	builtin_chr(char **argv, t_input *input)
{
	size_t	size_argv;

	size_argv = my_strdlen(argv);
	if (!my_strcmp(argv[0], "env"))
	{
		if (size_argv > 1)
			print_error(argv[0], -1);
		else
			g_status = ms_env(input);
	}
	else if (!my_strcmp(argv[0], "pwd"))
	{
		if (size_argv > 1)
			print_error(argv[0], -1);
		else
			g_status = ms_pwd(input);
	}
	else if (!my_strcmp(argv[0], "cd"))
	{
		if (size_argv > 2)
			print_error(argv[0], -1);
		else
			g_status = ms_cd(argv[1], input);
	}
	return (buildtin_chr_suite(argv, input));
}

static int	buildtin_chr_suite(char **argv, t_input *input)
{
	int		i;

	i = 1;
	if (!my_strcmp(argv[0], "export"))
	{
		if (argv[1])
			while (argv[i])
				g_status = ms_export(argv[i++], input);
		if (!argv[1])
			g_status = ms_export(NULL, input);
	}
	else if (!my_strcmp(argv[0], "unset") && argv[1])
		while (argv[i])
			g_status = ms_unset(argv[i++], input);
	else if (!my_strcmp(argv[0], "echo"))
		g_status = ms_echo(argv);
	else if (!my_strcmp(argv[0], "exit"))
		ms_exit(input, 0);
	else
		return (0);
	return (1);
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
