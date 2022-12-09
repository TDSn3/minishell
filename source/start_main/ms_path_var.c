/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_path_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 08:53:41 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/08 23:36:50 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*																			  */
/*   Export la variable d'environnement MS_PATH si elle n'éxiste pas.		  */
/*   Cette variable permet d'executer minishell dans un minishell.			  */
/*																			  */
/* ************************************************************************** */
int	ms_path_var(char **argv, t_input *input)
{
	char	*ms_path;
	char	*stock;

	if (!ms_get_env("MS_PATH", input) && input->env)
	{
		ms_path = ft_strjoin("MS_PATH=", ms_get_env("PWD", input));
		if (!ms_path)
			return (1);
		stock = ms_path;
		if (argv[0][0] == '.')
			ms_path = ft_strjoin(ms_path, argv[0] + 1);
		else
			ms_path = ft_strjoin(ms_path, argv[0]);
		free(stock);
		ms_export(ms_path, input);
		free(ms_path);
	}
	return (0);
}
