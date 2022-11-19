/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:21:52 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/16 12:32:39 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	int		tab[] = { 10, 15, 30, 50, 100};
	int		tab2[] = { 10, 15, 30, 50, 100};
	size_t	size_tab = sizeof(int) * 5;
	int		i = 0;

	while (i < 5)
	{
		printf("%d ", tab[i]);
		i++;
	}
	i = 0;
	printf("\n");
	
	memset(tab, 3, size_tab);
	
	while (i < 5)
	{
		printf("%d ", tab[i]);
		i++;
	}
	i = 0;
	printf("\n");

	ft_memset(tab2, 3, size_tab);
	
	while (i < 5)
	{
		printf("%d ", tab2[i]);
		i++;
	}
	printf("\n");


	char str[] = "almost every programmer should know memset!";
	memset (str,'&',12);
	puts (str);


	

	return (0);
}

*/
