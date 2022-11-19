/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:57:29 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/16 12:36:05 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	size_dst;

	i = 0;
	j = 0;
	size_dst = ft_strlen(dst);
	if (size > size_dst)
	{
		while (dst[i])
			i++;
		while (src[j] && i < size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (size_dst + ft_strlen(src));
	}
	else
		return (size + ft_strlen(src));
}
/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	dst1[20] = "Un ,"; // 4
	char	src1[] = "deux ,"; // 6
	int		un = strlcat(dst1, src1, 100); // 10 + 1

	printf("\n    | %s\t| return : %d\n", dst1, un);

//----------------------------------------------------------------------------//
	
	char	dst11[20] = "Un ,"; // 4
	char	src11[] = "deux ,"; // 6
	un = ft_strlcat(dst11, src11, 100); // 10 + 1

	printf("ft_ | %s\t| return : %d\n\n", dst11, un);

	return (0);
}
*/
