/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_oldpwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:17:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/28 10:26:41 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	get_oldpwd(char *str)
{
	char	**oldpwd;
	char	*save_for_free;
	char	*new_oldpwd;

	oldpwd = ms_get_env_start("OLDPWD=");
	save_for_free = *oldpwd;
	new_oldpwd = ft_strjoin("OLDPWD=", str);
	if (!new_oldpwd)
		return (1);
	*oldpwd = new_oldpwd;
	free(save_for_free);
	free(str);
	return (0);
}
