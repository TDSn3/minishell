/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strdlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:25:01 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/05 15:12:38 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	my_strdlen(char **strd)
{
	size_t	size;

	size = 0;
	if (!strd || !*strd)
		return (0);
	while (strd[size])
		size++;
	return (size);
}
