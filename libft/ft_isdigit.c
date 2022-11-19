/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:52:55 by tda-silv          #+#    #+#             */
/*   Updated: 2021/11/23 15:10:05 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*

#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	n = 'a';
	printf("o: %d\nft: %d\n\n", isdigit(n), ft_isdigit(n));
	int	n2 = 'A';
	printf("o: %d\nft: %d\n\n", isdigit(n2), ft_isdigit(n2));
	int	n3 = '0';
	printf("o: %d\nft: %d\n\n", isdigit(n3), ft_isdigit(n3));
	int	n4 = '9';
	printf("o: %d\nft: %d\n\n", isdigit(n4), ft_isdigit(n4));
	int	n5 = ' ';
	printf("o: %d\nft: %d\n\n", isdigit(n5), ft_isdigit(n5));
	int	n6 = 0;
	printf("o: %d\nft: %d\n\n", isdigit(n6), ft_isdigit(n6));
	return (0);
}

*/
