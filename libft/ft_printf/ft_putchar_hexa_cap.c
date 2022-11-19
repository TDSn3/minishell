/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_hexa_cap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:29:25 by tda-silv          #+#    #+#             */
/*   Updated: 2022/04/01 17:06:26 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_hexa_cap(char c, t_data *data)
{
	if (c < 10 + '0' && c >= '0')
		write(1, &c, 1);
	else if (c == 10 + '0')
		write(1, "A", 1);
	else if (c == 11 + '0')
		write(1, "B", 1);
	else if (c == 12 + '0')
		write(1, "C", 1);
	else if (c == 13 + '0')
		write(1, "D", 1);
	else if (c == 14 + '0')
		write(1, "E", 1);
	else if (c == 15 + '0')
		write(1, "F", 1);
	data->nbr_return += 1;
}
