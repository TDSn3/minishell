/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_break.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:17:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/29 21:17:35 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	is_break(t_type type)
{
	if (type == PIPE || type == GREDIR
		|| type == GRREDIR || type == DREDIR || type == DRREDIR)
		return (1);
	return (0);
}
