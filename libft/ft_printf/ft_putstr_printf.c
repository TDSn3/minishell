/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:44:27 by tda-silv          #+#    #+#             */
/*   Updated: 2022/04/01 17:06:13 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_printf(const char *s, t_data *data)
{
	size_t	i;

	i = 0;
	while ((s + data->pos)[i] && (s + data->pos)[i] != '%')
	{
		write (1, &(s + data-> pos)[i++], 1);
		data->nbr_return += 1;
	}
	if ((s + data->pos)[i] == '%')
		return (1);
	else
		return (0);
}
