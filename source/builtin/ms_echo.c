/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:46:28 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/07 13:14:58 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	multiple_option(char **argv);
static int	option_n(char *str);
static void	print_argv(char **argv, int i);

int	ms_echo(char **argv)
{
	int	i;

	if (!argv || !*argv || !**argv)
		return (1);
	if (argv[1])
	{
		i = multiple_option(argv);
		if (i > 1)
		{
			if (argv[i])
				print_argv(argv, i);
		}
		else
		{
			print_argv(argv, i);
			printf("\n");
		}
	}
	else
		printf("\n");
	return (0);
}

static int	multiple_option(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!option_n(argv[i]))
			return (i);
		i++;
	}
	return (i);
}

static int	option_n(char *str)
{
	int	i;

	i = 1;
	if (str && *str && *str == '-')
	{
		if (*(str + 1))
		{
			while (str[i])
			{
				if (str[i] != 'n')
					return (0);
				i++;
			}
			return (1);
		}
	}
	return (0);
}

static void	print_argv(char **argv, int i)
{
	while (argv[i])
	{
		printf("%s", argv[i++]);
		if (argv[i])
			printf(" ");
	}
}
