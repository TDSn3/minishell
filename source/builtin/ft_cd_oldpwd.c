/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_oldpwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:17:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/22 18:19:17 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	ft_cd_oldpwd(void)
{
	char	**oldpwd;
	char	*save_for_free;
	char	*new_oldpwd;

	oldpwd = ft_get_env_start("OLDPWD=");
	save_for_free = *oldpwd;
	new_oldpwd = ft_strjoin("OLDPWD=", ft_get_env("PWD="));
	*oldpwd = new_oldpwd;
	free(save_for_free);
}
