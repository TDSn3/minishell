/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:21:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/16 12:39:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	a;
	size_t	b;

	i = 0;
	a = 0;
	b = 0;
	while ((s1[i] || s2[i]) && i < n)
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
/*
#include <stdio.h>
#include <string.h>

int	main (void)
{
	char	tab1[] = {-128};
	char	tab2[] = {0};
	int		a = strncmp(tab1 , tab2, 1);
	int		b = ft_strncmp(tab1 , tab2, 1);

	printf ("\n>> : %d\nft : %d\n\n", a, b);
	return (0);
}
*/
