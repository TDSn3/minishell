/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:57:56 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/16 12:33:18 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

/*
#include <stdio.h>
#include <strings.h>

int main( void )
{
    int		i;
	char 	buffer[3];
	char 	mytab[3];
	
	i = 0;
	buffer[0] = 'S';
	buffer[1] = 'a';
	buffer[2] = '\0';
	mytab[0] = 'S';
	mytab[1] = 'a';
	mytab[2] = '\0';

//----

	printf("|%s\n", buffer);
    bzero(buffer, 1);
	
	printf("|");
	while (i < 3)
	{
		printf(" %d |", buffer[i]);
		i++;
	}

	i = 0;
	printf("\n\n");
	
	printf("|%s\n", mytab);
    ft_bzero(mytab, 1);
	
	printf("|");
	while (i < 3)
	{
		printf(" %d |", mytab[i]);
		i++;
	}

	i = 0;
*/
//---v ERROR v---
/*
	char *tab2 = "Sa";

	printf("\n\n%s\n", tab2);
    ft_bzero(tab2, 1);
	
	printf("|");
	while (i < 3)
	{
		printf(" %d |", tab2[i]);
		i++;
	}

	i = 0;
*/
//----
/*
	int	tab3[3] = { 10, 15, 30};

	printf("\n\n|");
	while (i < 3)
	{
		printf(" %d |", tab3[i]);
		i++;
	}

	i = 0;
	bzero(tab3, 8);

	printf("\n|");
	while (i < 3)
	{
		printf(" %d |", tab3[i]);
		i++;
	}

	i = 0;
	
//----

	int	tab4[3] = { 10, 15, 30};

	printf("\n\n|");
	while (i < 3)
	{
		printf(" %d |", tab4[i]);
		i++;
	}

	i = 0;
	ft_bzero(tab4, 8);

	printf("\n|");
	while (i < 3)
	{
		printf(" %d |", tab4[i]);
		i++;
	}

	i = 0;

    return (0);
}
*/
