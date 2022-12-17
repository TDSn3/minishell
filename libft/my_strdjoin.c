/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strdjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:27:43 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/15 10:34:49 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**creat_or_no(char *s);

char	**my_strdjoin(char **strd, char *s)
{
	int		i;
	int		x;
	int		y;
	char	**copy;

	if (!strd || !*strd || !**strd)
		return (creat_or_no(s));
	x = my_strdlen(strd) + 1;
	copy = ft_calloc(x + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < x - 1)
	{
		y = ft_strlen(strd[i]);
		copy[i] = ft_calloc(y + 1, sizeof(char));
		if (!copy[i])
			return (NULL);
		ft_strlcpy(copy[i], strd[i], y + 1);
		i++;
	}
	copy[i] = ft_strdup(s);
	copy[x] = NULL;
	return (copy);
}

static char	**creat_or_no(char *s)
{
	char	**copy;

	if (!s)
		return (NULL);
	copy = ft_calloc(2, sizeof(char *));
	if (!copy)
		return (NULL);
	copy[0] = ft_strdup(s);
	copy[1] = NULL;
	return (copy);
}
