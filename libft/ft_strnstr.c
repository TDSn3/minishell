/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:14:02 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/16 12:39:58 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (big[i + j] == little[j] && i + j < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		j = 0;
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <bsd/string.h> // compile with -lbsd

int	main(void)
{
	char	big[] = "Une super phrase de test !"; // 26
	char	little[] = "super";
	
	printf("\n%s\n\n", strnstr(big, little, 26));
	printf("\n%s\n\n", ft_strnstr(big, little, 26));
	return (0);
}
*/
