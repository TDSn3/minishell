/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_oldpwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:17:46 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/09 02:17:32 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	get_oldpwd(char *str, t_input *input)
{
	char	**oldpwd;
	char	*save_for_free;
	char	*new_oldpwd;

	save_for_free = NULL;
	oldpwd = ms_get_env_start("OLDPWD", input);
	if (oldpwd)
		save_for_free = *oldpwd;
	new_oldpwd = ft_strjoin("OLDPWD=", str);
	if (!new_oldpwd)
		return (1);
	if (!oldpwd)
	{
		ms_export(new_oldpwd, input);
		if (new_oldpwd)
			free(new_oldpwd);
	}
	else
		*oldpwd = new_oldpwd;
	if (save_for_free)
		free(save_for_free);
	if (str)
		free(str);
	return (0);
}
