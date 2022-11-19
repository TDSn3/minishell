/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:16:33 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/19 18:23:28 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	map_add(t_map **lst, t_map *new)
{
	t_map	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		(*lst)->key = 0;
		return ;
	}
	tmp = map_last(*lst);
	tmp->next = new;
	tmp->next->key = tmp->key + 1;
}
