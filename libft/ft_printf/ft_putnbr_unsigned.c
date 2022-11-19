/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:05:52 by tda-silv          #+#    #+#             */
/*   Updated: 2022/04/01 17:03:16 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int nbr, t_data *data)
{
	if (nbr > 9)
		ft_putnbr_unsigned(nbr / 10, data);
	ft_putchar(nbr % 10 + '0', data);
}
