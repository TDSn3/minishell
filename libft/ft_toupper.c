/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:41:44 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/16 12:35:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c -= 32);
	else
		return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	tab[] = "super";
	
	tab[2] = ft_toupper(tab[2]);
	printf("\n%d | %d | %s\n\n", tab[2], toupper(tab[2]), tab);
	printf("\n%d | %d | %s\n\n", tab[2], ft_toupper(tab[2]), tab);
	return (0);
}
*/
