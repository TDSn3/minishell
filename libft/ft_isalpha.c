/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:52:55 by tda-silv          #+#    #+#             */
/*   Updated: 2021/12/13 11:21:05 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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
	printf("o: %d\nft: %d\n\n", isalpha(n), ft_isalpha(n));
	int	n2 = 'A';
	printf("o: %d\nft: %d\n\n", isalpha(n2), ft_isalpha(n2));
	int	n3 = 'z';
	printf("o: %d\nft: %d\n\n", isalpha(n3), ft_isalpha(n3));
	int	n4 = 'Z';
	printf("o: %d\nft: %d\n\n", isalpha(n4), ft_isalpha(n4));
	int	n5 = ' ';
	printf("o: %d\nft: %d\n\n", isalpha(n5), ft_isalpha(n5));
	int	n6 = 0;
	printf("o: %d\nft: %d\n\n", isalpha(n6), ft_isalpha(n6));
	return (0);
}

*/
