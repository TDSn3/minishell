/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env_in_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:47:36 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/28 10:09:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	free_function_all(void);

int	copy_env_in_export(void)
{
	int	i;

	i = 0;
	if (!g_d.env)
		return (0);
	while (g_d.env[i])
	{
		if (ls_add_back(&(g_d.export), ls_new(ft_strdup(g_d.env[i]))))
			return (free_function_all()); // A TESTER // ERROR MALLOC
		i++;
	}
	return (0);
}

static int	free_function_all(void)
{
	ls_clear(&(g_d.export));
	return (1);
}
