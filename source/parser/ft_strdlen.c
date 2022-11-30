/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:35:47 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/30 00:35:58 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

size_t	ft_strdlen(char **strd)
{
	int	count;

	count = 0;
	if (!strd || !strd[0])
		return (0);
	while (strd && strd[count])
		count ++;
	return (count);
}
