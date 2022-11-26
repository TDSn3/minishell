/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:29:00 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/26 20:39:32 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	ms_env(void)
{
	int		i;

	i = 0;
	if (g_d.env)
		while (g_d.env[i])
			printf("%s\n", g_d.env[i++]);
	return (0);
}

/*	Avec de la couleur
	int		pos;
	char	*after_equal;

	if (g_d.env && *(g_d.env) && **(g_d.env))
	{
		while (g_d.env[i])
		{
			after_equal = ft_strchr(g_d.env[i], '=');
			if (after_equal)
				after_equal += 1;
			pos = my_strchr_pos(g_d.env[i], '=');
			if (pos > -1)
			{
				g_d.env[i][pos] = 0;
				printf("\033[36;01m%s\033[37;00m=", g_d.env[i]);
				g_d.env[i][pos] = '=';
				printf("\033[33m%s\033[00m\n", after_equal);
			}
			else
				printf("\033[36;01m%s\033[37;00m=", g_d.env[i]);
			i++;
		}
	}
*/