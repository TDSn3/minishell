/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idconv_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:46:19 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/31 17:46:42 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_idconv_p(t_data *data, va_list *ellipse)
{
	data->p = va_arg(*ellipse, unsigned long long int);
	if (data->p != 0)
	{
		write(1, "0x", 2);
		data->nbr_return += 2;
		ft_putnbr_hexa(data->p, data);
	}
	else
	{
		write(1, "(nil)", 5);
		data->nbr_return += 5;
	}
	data->pos += 1;
}
