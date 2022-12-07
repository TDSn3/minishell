/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_path_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 08:53:41 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/07 09:26:33 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*																			  */
/*   Export la variable d'environnement MS_PATH si elle n'éxiste pas.		  */
/*   Cette variable permet d'executer minishell dans un minishell.			  */
/*																			  */
/* ************************************************************************** */
int	ms_path_var(char **argv)
{
	char	*ms_path;
	char	*stock;

	if (!get_export("MS_PATH"))
	{
		ms_path = ft_strjoin("MS_PATH", ms_get_env("PWD"));
		if (!ms_path)
			return (1);
		stock = ms_path;
		if (argv[0][0] == '.')
			ms_path = ft_strjoin(ms_path, argv[0] + 1);
		else
			ms_path = ft_strjoin(ms_path, argv[0]);
		free(stock);
		ms_export(ms_path);
		free(ms_path);
	}
	return (0);
}
