/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:40:40 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/05 15:28:50 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	print_error(char *cmd, int nb_error);

int	builtin_chr(char **argv)
{
	int		i;
	size_t	size_argv;

	i = 1;
	size_argv = my_strdlen(argv);
	if (!my_strcmp(argv[0], "env"))
	{
		if (size_argv > 1)
			print_error(argv[0], -1);
		else
			ms_env();
		return (1);
	}
	if (!my_strcmp(argv[0], "pwd"))
	{
		if (size_argv > 1)
			print_error(argv[0], -1);
		else
			ms_pwd();
		return (1);
	}
	if (!my_strcmp(argv[0], "cd"))
	{
		if (size_argv > 2)
			print_error(argv[0], -1);
		else
			ms_cd(argv[1]);
		return (1);
	}
	if (!my_strcmp(argv[0], "export"))
	{
		if (argv[1])
			while (argv[i])
				ms_export(argv[i++]);
		if (!argv[1])
			ms_export(NULL);
		return (1);
	}
	if (!my_strcmp(argv[0], "unset"))
	{
		if (argv[1])
			while (argv[i])
				ms_unset(argv[i++]);
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
