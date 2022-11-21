/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:17:38 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/22 00:20:07 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	update_env_home(const char *str);
static int	update_env(const char *str);

int	ft_cd(const char *path)
{
	int			res;
	const char	*str;

	if (!path || !*path)
	{
		str = (const char *)ft_get_env("HOME=");
		if (str)
		{
			res = chdir(str);
			if (res < 0 || update_env_home(str))
			{
				perror("cd");
				return (1);
			}
		}
		return (0);
	}
	res = chdir(path);
	if (res < 0 || update_env(path))
	{
		perror("cd");
		return (1);
	}
	return (0);
}

static int	update_env_home(const char *str)
{
	char	**pwd;
	char	*save_for_free;
	char	*new_pwd;
	char	*stock;

	pwd = ft_get_env_start("PWD=");
	save_for_free = *pwd;
	new_pwd = calloc(ft_strlen(str) + 5, sizeof(char));
	if (!new_pwd)
		return (1);
	stock = ft_strjoin("PWD=", str);
	if (!stock)
		return (1);
	ft_strlcpy(new_pwd, stock, ft_strlen(str) + 5);
	*pwd = new_pwd;
	free(stock);
	free(save_for_free);
	return (0);
}

static int	update_env(const char *str)
{
	char	**pwd;
	char	*save_for_free;
	char	*new_pwd;
	char	*stock;

	pwd = ft_get_env_start("PWD=");
	save_for_free = *pwd;
	stock = ft_strjoin("/", str);
	if (str[ft_strlen(str) - 1] == '/')
	{
		stock[ft_strlen(stock) - 1] = 0;
		new_pwd = ft_strjoin(*ft_get_env_start("PWD="), stock);
		stock[ft_strlen(stock) - 1] = '/';
	}
	else
		new_pwd = ft_strjoin(*ft_get_env_start("PWD="), stock);
	if (!new_pwd)
		return (1);
	*pwd = new_pwd;
	free(stock);
	free(save_for_free);
	return (0);
}
