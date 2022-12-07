/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:07:29 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/07 20:51:49 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	update_env(const char *str, t_input *input)
{
	char	**pwd;
	char	*save_for_free;

	pwd = ms_get_env_start("PWD=", input);
	save_for_free = *pwd;
	*pwd = ft_strjoin("PWD=", str);
	if (!*pwd)
		return (1);
	free(save_for_free);
	return (0);
}
