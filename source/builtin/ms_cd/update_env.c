/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:07:29 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/05 19:08:52 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	update_env(const char *str)
{
	char	**pwd;
	char	*save_for_free;

	pwd = ms_get_env_start("PWD=");
	save_for_free = *pwd;
	*pwd = ft_strjoin("PWD=", str);
	if (!*pwd)
		return (1);
	free(save_for_free);
	return (0);
}
