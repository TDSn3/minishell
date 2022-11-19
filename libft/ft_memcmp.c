/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:08:16 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/16 12:39:38 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s1)[i] != ((char *)s2)[i])
			return ((((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

#define NCHAR 5
#define NINT 5

int	main(void)
{
	char	tab1[] = "SAlut";
	char	tab2[] = "Salut";
	int		tab11[] = { -128, 0, 127, 0 };
	int		tab22[] = { 0, 0, 127, 0 };
	
	printf("\no: %d | m: %d ", memcmp(tab1, tab2, NCHAR), 
ft_memcmp(tab1, tab2, NCHAR));
	printf("%s\n", (memcmp(tab1, tab2, NCHAR) == 
ft_memcmp(tab1, tab2, NCHAR) ? "OK" : "NO"));

	printf("\no: %d | m: %d ", memcmp(tab11, tab22, NINT), 
ft_memcmp(tab11, tab22, NINT));
	printf("%s\n\n", (memcmp(tab11, tab22, NINT) == 
ft_memcmp(tab11, tab22, NINT) ? "OK" : "NO"));
	
	return(0);
}
*/
