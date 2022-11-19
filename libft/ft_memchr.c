/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:09:33 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/16 12:39:26 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == (char)c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FOUND 258
#define SIZE 3

int 	main (void)
{
	char 	tab[] = { 0, 1, 2, 3, 4, 5 };
	
	printf("\n-- memchr :%s\n", (memchr(tab, FOUND, SIZE) != NULL ?
 "Found" : "Not found"));
	printf("ft_memchr :%s ", (ft_memchr(tab, FOUND, SIZE) != NULL ?
 "Found" : "Not found"));
	memchr(tab, FOUND, SIZE) == ft_memchr(tab, FOUND, SIZE) ? 
printf("OK\n\n") : printf("\nNO\n");
//	NE MARCHE QU'AVEC DES VALEURS TROUVABLES

//	printf("\n%d\n", *(char *)memchr(tab, FOUND, 5));
//	printf("\n%d\n\n", *(char *)ft_memchr(tab, FOUND, 5));
	return (0);
}
*/
