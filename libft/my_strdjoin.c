/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strdjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:27:43 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/24 13:27:52 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**my_strdjoin(char **strd, char *s)
{
	int		i;
	int		x;
	int		y;
	char	**copy;

	if (!strd || !*strd || !**strd)
		return (NULL);
	x = my_strdlen(strd) + 1;
	copy = calloc(x + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < x - 1)
	{
		y = ft_strlen(strd[i]);
		copy[i] = calloc(y + 1, sizeof(char));
		if (!copy[i])
			return (NULL);
		ft_strlcpy(copy[i], strd[i], y + 1);
		i++;
	}
	copy[i] = ft_strdup(s);
	copy[x] = NULL;
	return (copy);
}
