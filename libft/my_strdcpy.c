/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strdcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:27:43 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/21 22:28:01 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**my_strdcpy(char **strd)
{
	int		i;
	int		x;
	int		y;
	char	**copy;

	if (!strd || !*strd || !**strd)
		return (NULL);
	x = my_strdlen(strd);
	copy = calloc(x + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	strd[x] = NULL;
	i = 0;
	while (i < x)
	{
		y = ft_strlen(strd[i]);
		copy[i] = calloc(y + 1, sizeof(char));
		if (!copy[i])
			return (NULL);
		ft_strlcpy(copy[i], strd[i], y + 1);
		i++;
	}
	return (copy);
}
