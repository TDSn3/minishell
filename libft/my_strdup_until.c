/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strdup_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:31:35 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/24 17:49:01 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*																			  */
/*   Duplique s jusqu'au premier caractère c inclu.							  */
/*																			  */
/* ************************************************************************** */
char	*my_strdup_until(const char *s, char c)
{
	char	*copy;
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			break ;
		}
		i++;
	}
	copy = ft_calloc(i + 1, sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, i + 1);
	return (copy);
}
