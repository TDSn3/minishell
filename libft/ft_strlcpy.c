/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:32:40 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/16 12:36:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size)
		{
			dst[i] = src[i];
			i++;
		}
		if (size > ft_strlen(src))
			dst[i] = '\0';
		else
			dst[i - 1] = '\0';
	}
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	dst1[] = "Super test !";
	char	src1[] = "SUPRA";

	printf("\nCas normal :\ndst : %s\t|<-| src: %s\n", dst1, src1);
	size_t	un = strlcpy(dst1, src1, 6);
	printf("dst : %s\t\t|  | return : %ld\n", dst1, un);
	
//----------------------------------------------------------------------------//

	char	dst2[] = "";
	char	src2[] = "SUPRA";

	printf("\ndst vide :\ndst : %s\t\t\t|<-| src: %s\n", dst2, src2);
	un = strlcpy(dst2, src2, 6);
	printf("dst : %s\t\t|  | return : %ld\n\n", dst2, un);

//----------------------------------------------------------------------------//

	char	dst3[] = "Super test !";
	char	src3[] = "0123456789ABCDEFG";

	printf("\nsrc plus grand que dst :\ndst : %s\t|<-| src: %s\n", dst3, src3);
	un = strlcpy(dst3, src3, 18);
	printf("dst : %s\t|  | return : %ld\n\n", dst3, un);

//----------------------------------------------------------------------------//

	char	dst4[] = "Super test !";
	char	src4[] = "";

	printf("\nsrc vide :\ndst : %s\t|<-| src: %s\n", dst4, src4);
	un = strlcpy(dst4, src4, 18);
	printf("dst : %s\t\t\t|  | return : %ld\n\n", dst4, un);

//----------------------------------------------------------------------------//

	char	dst5[] = "Super test !";
	char	src5[] = "Non";

	printf("\nCopie 0 caractères :\ndst : %s\t|<-| src: %s\n", dst5, src5);
	un = strlcpy(dst5, src5, 0);
	printf("dst : %s\t|  | return : %ld\n\n", dst5, un);

//----------------------------------------------------------------------------//

	printf("\n----------\nft_strlcpy\n----------\n\n");

//----------------------------------------------------------------------------//

	char	dst11[] = "Super test !";
	char	src11[] = "SUPRA";

	printf("\nCas normal :\ndst : %s\t|<-| src: %s\n", dst11, src11);
	un = ft_strlcpy(dst11, src11, 6);
	printf("dst : %s\t\t|  | return : %ld\n", dst11, un);
	
//----------------------------------------------------------------------------//

	char	dst22[] = "";
	char	src22[] = "SUPRA";

	printf("\ndst vide :\ndst : %s\t\t\t|<-| src: %s\n", dst22, src22);
	un = ft_strlcpy(dst22, src22, 6);
	printf("dst : %s\t\t|  | return : %ld\n\n", dst22, un);

//----------------------------------------------------------------------------//

	char	dst33[] = "Super test !";
	char	src33[] = "0123456789ABCDEFG";

	printf("\nsrc plus grand que dst :\ndst : %s\t|<-| src: %s\n", dst33, src33);
	un = ft_strlcpy(dst33, src33, 18);
	printf("dst : %s\t|  | return : %ld\n\n", dst33, un);

//----------------------------------------------------------------------------//

	char	dst44[] = "Super test !";
	char	src44[] = "";

	printf("\nsrc vide :\ndst : %s\t|<-| src: %s\n", dst44, src44);
	un = ft_strlcpy(dst44, src44, 18);
	printf("dst : %s\t\t\t|  | return : %ld\n\n", dst44, un);

//----------------------------------------------------------------------------//

	char	dst55[] = "Super test !";
	char	src55[] = "Non";

	printf("\nCopie 0 caractères :\ndst : %s\t|<-| src: %s\n", dst55, src55);
	un = ft_strlcpy(dst55, src55, 0);
	printf("dst : %s\t|  | return : %ld\n\n", dst55, un);


	return (0);
}
*/
