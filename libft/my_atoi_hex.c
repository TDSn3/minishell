/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:58:31 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/30 10:14:11 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	part_two(const char *nptr, unsigned int *nb, unsigned int *i);

long long int	my_atoi_hex(const char *nptr)
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
	if (nptr[i] == '0' && nptr[i + 1] == 'x')
		i += 2;
	part_two(nptr, &nb, &i);
	return (final_nb = nb * if_is_negative);
}

void	part_two(const char *nptr, unsigned int *nb, unsigned int *i)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if (nptr[*i] >= '0' && nptr[*i] <= '9')
			*nb = (*nb * 16) + (nptr[*i] - 48);
		else if (nptr[*i] >= 'A' && nptr[*i] <= 'F')
			*nb = (*nb * 16) + (nptr[*i] - 55);
		else if (nptr[*i] >= 'a' && nptr[*i] <= 'f')
			*nb = (*nb * 16) + (nptr[*i] - 87);
		else
			return ;
		*i += 1;
		j++;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
//	char	tab1[] = "-102";
	long long int		t1 = atoi(argv[1]);
	long long int		t2 = my_atoi_hex(argv[1]);

	(void)argc;
	printf("\n%s : %lld | %lld\n\n", argv[1], t1, t2);
	return (0);
}
*/
