/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:33:10 by tda-silv          #+#    #+#             */
/*   Updated: 2021/11/23 15:42:37 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*

#include <stdio.h>
#include <ctype.h>

int main(void)
{
int n = 0;
printf("o: %d\nft: %d\n\n", isascii(n), ft_isascii(n));
int n2 = -1;
printf("o: %d\nft: %d\n\n", isascii(n2), ft_isascii(n2));
int n3 = -127;
printf("o: %d\nft: %d\n\n", isascii(n3), ft_isascii(n3));
int n4 = 127;
printf("o: %d\nft: %d\n\n", isascii(n4), ft_isascii(n4));
int n5 = 255;
printf("o: %d\nft: %d\n\n", isascii(n5), ft_isascii(n5));
int n6 = 50;
printf("o: %d\nft: %d\n\n", isascii(n6), ft_isascii(n6));
return (0);
}

*/
