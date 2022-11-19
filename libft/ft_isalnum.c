/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:15:07 by tda-silv          #+#    #+#             */
/*   Updated: 2021/12/13 11:19:00 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

/*

#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int n = 'a';
	printf("o: %d\nft: %d\n\n", isalnum(n), ft_isalnum(n));
	int n2 = 'A';
	printf("o: %d\nft: %d\n\n", isalnum(n2), ft_isalnum(n2));
	int n3 = '0';
	printf("o: %d\nft: %d\n\n", isalnum(n3), ft_isalnum(n3));
	int n4 = '9';
	printf("o: %d\nft: %d\n\n", isalnum(n4), ft_isalnum(n4));
	int n5 = ' ';
	printf("o: %d\nft: %d\n\n", isalnum(n5), ft_isalnum(n5));
	int n6 = 0;
	printf("o: %d\nft: %d\n\n", isalnum(n6), ft_isalnum(n6));

	return (0);
}

*/
