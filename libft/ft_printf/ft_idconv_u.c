/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idconv_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:10:03 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/31 16:10:48 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_idconv_u(t_data *data, va_list *ellipse)
{
	data->u = va_arg(*ellipse, unsigned int);
	ft_putnbr_unsigned(data->u, data);
	data->pos += 1;
}
