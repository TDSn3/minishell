/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:22:50 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/24 20:25:50 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (s)
	{
		while (i >= 0)
		{
			if (s[i] == (char)c)
				return ((char *)s + i);
			i--;
		}
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
#define SEARCH 's'

int main(void)
{
    char    tab[] = "saluts";
    printf("\n-- strrchr :%d", strrchr(tab, SEARCH));
    printf("\nft_strrchr :%d ", ft_strrchr(tab, SEARCH));
    strrchr(tab, SEARCH) == ft_strrchr(tab, SEARCH) ? 
printf("OK\n\n") : printf("NO\n\n");
    return (0);
}
*/
