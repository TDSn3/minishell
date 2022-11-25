/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:27:43 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/25 10:01:35 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	copy_env(char **strd)
{
	int		i;
	int		x;
	int		y;
	char	**copy;

	if (!strd || !*strd || !**strd)
		return (0);
	x = my_strdlen(strd);
	copy = calloc(x + 1, sizeof(char *));
	if (!copy)
		return (1);
	i = 0;
	while (i < x)
	{
		y = ft_strlen(strd[i]);
		copy[i] = calloc(y + 1, sizeof(char));
		if (!copy[i])
			return (1);
		ft_strlcpy(copy[i], strd[i], y + 1);
		i++;
	}
	copy[x] = NULL;
	g_d.env = copy;
	return (0);
}
