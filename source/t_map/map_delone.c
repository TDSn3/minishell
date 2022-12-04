/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_delone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:57:51 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/04 16:45:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	map_delone(t_map *lst, void (*del)(void*))
{
	if (!del || !lst)
		return ;
	if (lst->content)
		del(lst->content);
	free(lst);
}
