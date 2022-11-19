/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:55:29 by tda-silv          #+#    #+#             */
/*   Updated: 2022/04/01 17:02:49 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_int(int nbr, t_data *data)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		data->nbr_return += 11;
	}
	else
	{
		if (nbr < 0)
		{
			nbr *= -1;
			write(1, "-", 1);
			data->nbr_return += 1;
		}
		if (nbr > 9)
			ft_putnbr_int(nbr / 10, data);
		ft_putchar(nbr % 10 + '0', data);
	}
}
