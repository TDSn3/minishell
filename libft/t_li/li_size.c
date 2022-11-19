/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:59:36 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/24 20:38:32 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	li_size(t_li *lst)
{
	t_li	*nextl;
	size_t	i;

	i = 0;
	nextl = lst;
	if (!lst)
		return (0);
	while (nextl)
	{
		nextl = nextl->next;
		i++;
	}
	return (i);
}
