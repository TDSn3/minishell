/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_off.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:10:02 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/11 11:12:29 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	handler_off(int sig)
{
	int	return_write;

	return_write = 0;
	(void) return_write;
	if (sig == 2)
		return ;
	if (sig == 3)
		return ;
}
