/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:07:29 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/12 16:47:31 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	update_env(const char *str, t_input *input)
{
	char	**pwd;
	char	*save_for_free;

	pwd = ms_get_env_start("PWD", input);
	if (!pwd)
	{
		ms_export(ft_strjoin("PWD=", str), input);
		return (0);
	}
	save_for_free = *pwd;
	*pwd = ft_strjoin("PWD=", str);
	if (!*pwd)
		return (1);
	free(save_for_free);
	return (0);
}
