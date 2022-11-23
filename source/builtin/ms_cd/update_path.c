/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:09:20 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/23 20:40:26 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	update_path(const char *path, char **path_update)
{
	char	*pwd_sans;
	char	*save_for_free;
	char	*stock;

	save_for_free = *path_update;
	pwd_sans = ms_get_env("PWD=");
	stock = ft_strjoin("/", path);
	if (!stock)
		return (1);
	*path_update = ft_strjoin(pwd_sans, stock);
	if (!*path_update)
		return (1);
	*path_update = remove_point(*path_update);
	free(save_for_free);
	return (0);
}
