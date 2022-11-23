/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env_home.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:08:39 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/23 20:39:58 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	update_env_home(const char *str)
{
	char	**pwd;
	char	*save_for_free;
	char	*new_pwd;
	char	*stock;

	pwd = ms_get_env_start("PWD=");
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
