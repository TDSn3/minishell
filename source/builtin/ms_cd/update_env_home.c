/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env_home.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:08:39 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/07 20:52:37 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	free_function_all(char **new_pwd);

int	update_env_home(const char *str, t_input *input)
{
	char	**pwd;
	char	*save_for_free;
	char	*new_pwd;
	char	*stock;

	pwd = ms_get_env_start("PWD=", input);
	save_for_free = *pwd;
	new_pwd = calloc(ft_strlen(str) + 5, sizeof(char));
	if (!new_pwd)
		return (1);
	stock = ft_strjoin("PWD=", str);
	if (!stock)
		return (free_function_all(&new_pwd));
	ft_strlcpy(new_pwd, stock, ft_strlen(str) + 5);
	*pwd = new_pwd;
	free(stock);
	free(save_for_free);
	return (0);
}

static int	free_function_all(char **new_pwd)
{
	free(*new_pwd);
	return (1);
}
