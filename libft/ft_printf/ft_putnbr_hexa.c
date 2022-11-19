/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:08:57 by tda-silv          #+#    #+#             */
/*   Updated: 2022/04/01 17:03:54 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexa(unsigned long long int nbr, t_data *data)
{
	if (nbr > 15)
		ft_putnbr_hexa(nbr / 16, data);
	ft_putchar_hexa(nbr % 16 + '0', data);
}
