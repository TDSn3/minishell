/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:42:30 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/16 12:33:59 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	int	i = 0;
	int	tab[] = { 10, 15, 30, 100}; //tab[4]
	int	*tab2;
	
	tab2 = malloc(4 * sizeof(int));
	if (!tab2)
		return (-1);

	while (i < 4)
		printf("%d ", tab[i++]);

	memcpy(tab2, tab, 4); // 4 * sizeof(int)

	i = 0;
	printf("\n\n");
	while (i < 4)
		printf("%d ", tab2[i++]);

	free(tab2);

//---- 
	printf("\n---\n");
//----
 
	i = 0;
	int	tab3[] = { 10, 15, 30, 100}; //tab3[4]
	int	*tab4;
	
	tab4 = malloc(4 * sizeof(int));
	if (!tab4)
		return (-1);

	while (i < 4)
		printf("%d ", tab3[i++]);

	ft_memcpy(tab4, tab3, 4); // 4 * sizeof(int)

	i = 0;
	printf("\n\n");
	while (i < 4)
		printf("%d ", tab4[i++]);

	free(tab4);

//---- 

	return (0);
}
*/
