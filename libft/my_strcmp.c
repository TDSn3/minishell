/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:21:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/24 13:51:42 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	size_t	a;
	size_t	b;

	i = 0;
	a = 0;
	b = 0;
	if (!s1 || !*s1 || !s2 || !*s2)
		return (1);
	while (s1[i] || s2[i])
	{
		if (s1[i])
			a += s1[i];
		if (s2[i])
			b += s2[i];
		if (a != b)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			i++;
	}
	return (0);
}
