/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_remove_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:18:28 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/23 08:47:05 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*																			  */
/*   Supprime les ".."" du path de cd et supprime leurs répertoires			  */
/*   antérieurs.															  */
/*																			  */
/* ************************************************************************** */
char	*ft_cd_remove_point(char *str)
{
	char	*copy;
	char	*save_for_free;
	char	*stock_one;
	char	*stock_two;
	char	*stock_three;
	int		i;

	i = 0;
	copy = ft_strdup(str);
	if (!copy)
		return (NULL);
	while (copy[i])
	{
		if (copy[i] == '.')
		{
			i++;
			if (copy[i] == '.' && (!copy[i + 1] || copy[i + 1] == '/'))
			{
				stock_one = ft_substr(copy, 0, i - 2);
				stock_two = ft_substr(copy, 0, (i - 1) - ft_strlen(
							ft_strrchr(stock_one, '/')));
				stock_three = ft_substr(copy, i + 2, ft_strlen(copy + (i + 2)));
				save_for_free = copy;
				copy = ft_strjoin(stock_two, stock_three);
				free(save_for_free);
				free(stock_one);
				free(stock_two);
				free(stock_three);
			}
			i = 0;
			continue ;
		}
		i++;
	}
	if (copy[ft_strlen(copy) - 1] == '/' && ft_strlen(copy) > 5)
	{
		save_for_free = copy;
		copy = ft_substr(copy, 0, ft_strlen(copy) - 1);
		printf("%s\n", copy);
		free(save_for_free);
	}
	free(str);
	return (copy);
}
