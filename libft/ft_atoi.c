/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:58:31 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/31 14:34:37 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	unsigned int		i;
	unsigned int		nb;
	long long int		final_nb;
	int					if_is_negative;

	i = 0;
	nb = 0;
	if_is_negative = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			if_is_negative = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nb * 10) + (nptr[i] - 48);
		i++;
	}
	return (final_nb = nb * if_is_negative);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
//	char	tab1[] = "-102";
	int		t1 = atoi(argv[1]);
	int		t2 = ft_atoi(argv[1]);

	(void)argc;
	printf("\n%s : %d | %d\n\n", argv[1], t1, t2);
	return (0);
}
*/
