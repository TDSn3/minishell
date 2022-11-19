/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:15:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/16 12:42:12 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(char *s)
{
	size_t	a;
	size_t	z;
	int		copy;

	a = 0;
	z = ft_strlen(s) - 1;
	while (a < z)
	{
		copy = s[a];
		s[a] = s[z];
		s[z] = copy;
		a++;
		z--;
	}
}

static void	ft_zero_or_neg(long int *n_copy, unsigned int *n_size, int *symbol)
{
	*n_size = 1;
	if (*n_copy < 0)
	{
		*n_copy *= -1;
		*symbol = 1;
	}
}

static char	*ft_cpy(unsigned int n_size, long int n_copy, char *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (i < n_size)
	{
		s[i] = ((n_copy / j) % 10) + 48;
		j *= 10;
		i++;
	}
	s[i] = 0;
	return (s);
}

char	*ft_itoa(int n)
{
	long int		n_copy;
	unsigned int	n_size;
	int				symbol;
	long int		n2;
	char			*s;

	n_copy = n;
	n_size = 0;
	symbol = 0;
	if (n <= 0)
		ft_zero_or_neg(&n_copy, &n_size, &symbol);
	n2 = n_copy;
	while (n2 > 0)
	{
		n2 /= 10;
		n_size++;
	}
	s = malloc(n_size + 1);
	if (!s)
		return (NULL);
	ft_swap(ft_cpy(n_size, n_copy, s));
	if (symbol)
		s[0] = '-';
	return (s);
}
/*
#include <stdio.h>

int main(void)
{
    char    *s = ft_itoa(0); // -2147483648
    printf("\ns:%s\n\n", s);
    free(s);
    return (0);
}
*/
