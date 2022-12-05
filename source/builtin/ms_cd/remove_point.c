/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:18:28 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/05 19:05:29 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	find_point(char **copy);

/* ************************************************************************** */
/*																			  */
/*   Supprime les ".." ou les "." du path de cd et supprime leurs			  */
/*   répertoires antérieurs.												  */
/*																			  */
/* ************************************************************************** */
char	*remove_point(char *str)
{
	int		size;
	char	*copy;
	char	*save;

	save = NULL;
	copy = ft_strdup(str);
	if (!copy || find_point(&copy))
	{
		if (copy)
			free(copy);
		return (NULL);
	}
	size = ft_strlen(copy);
	if (size > 5 && copy[size - 1] == '/')
	{
		save = copy;
		copy = ft_substr(copy, 0, size - 1);
		free(save);
	}
	free(str);
	return (copy);
}

static int	find_point(char **copy)
{
	int		i;

	i = 0;
	while ((*copy)[i])
	{
		if ((*copy)[i] == '.')
		{
			i++;
			if ((*copy)[i] == '.' && (!((*copy)[i + 1])
				|| (*copy)[i + 1] == '/'))
			{
				if (two_point(copy, i))
					return (1);
			}
			else if (!((*copy)[i]) || (*copy)[i] == '/')
				if (one_point(copy, i))
					return (1);
			i = 0;
			continue ;
		}
		i++;
	}
	if (ft_strlen(*copy) > 1 && remove_last(copy))
		return (1);
	return (0);
}
