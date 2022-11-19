/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:51:15 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/19 18:28:44 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy;
	size_t	flen;

	if (!s || start > ft_strlen(s) - 1)
	{
		copy = malloc(1);
		if (!copy)
			return (NULL);
		*copy = 0;
		return (copy);
	}
	flen = ft_strlen(s + start);
	if (len < flen)
		flen = len;
	copy = malloc(flen + 1);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s + start, flen + 1);
	return (copy);
}
/*
Alloue (avec malloc(3)) et retourne une chaîne de
caractères issue de la chaîne ’s’.
Cette nouvelle chaîne commence à l’index ’start’ et
a pour taille maximale ’len’.
*/
