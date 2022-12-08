/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:24:47 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/08 18:26:11 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	print_error(char *str_one, char *str_two, int nb_error);

/* ************************************************************************** */
/*																			  */
/*   Incrémente la variable SHLVL de 1 au lencement de minishell.			  */
/*																			  */
/* ************************************************************************** */
int	shlvl(t_input *input)
{
	char	*stock_str;
	char	*stock_for_free;
	int		stock_i;

	stock_str = ms_get_env("SHLVL", input);
	if (stock_str && *stock_str)
	{
		stock_i = ft_atoi(ms_get_env("SHLVL", input)) + 1;
		stock_for_free = ft_itoa(stock_i);
		stock_str = ft_strjoin("SHLVL=", stock_for_free);
		if (ms_unset("SHLVL", input) || ms_export(stock_str, input))
			return (print_error(stock_str, stock_for_free, 12));
		free(stock_str);
		free(stock_for_free);
	}
	return (0);
}

static int	print_error(char *str_one, char *str_two, int nb_error)
{
	errno = nb_error;
	perror("unset");
	if (str_one)
		free(str_one);
	if (str_two)
		free(str_two);
	return (1);
}
