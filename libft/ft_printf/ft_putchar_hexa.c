/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:27:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/04/01 17:04:36 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_hexa(char c, t_data *data)
{
	if (c < 10 + '0' && c >= '0')
		write(1, &c, 1);
	else if (c == 10 + '0')
		write(1, "a", 1);
	else if (c == 11 + '0')
		write(1, "b", 1);
	else if (c == 12 + '0')
		write(1, "c", 1);
	else if (c == 13 + '0')
		write(1, "d", 1);
	else if (c == 14 + '0')
		write(1, "e", 1);
	else if (c == 15 + '0')
		write(1, "f", 1);
	data->nbr_return += 1;
}
