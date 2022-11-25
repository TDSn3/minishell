/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env_in_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:47:36 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/25 10:37:55 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	copy_env_in_export(void)
{
	int	i;

	i = 0;
	if (!g_d.env)
		return (0);
	while (g_d.env[i])
	{
		if (ls_add_back(&(g_d.export), ls_new(ft_strdup(g_d.env[i]))))
			return (1);
		i++;
	}
	return (0);
}
