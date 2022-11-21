/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:49:45 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/21 19:59:25 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	map_clear(t_map **lst, void (*del)(void *))
{
	t_map	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		map_delone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
