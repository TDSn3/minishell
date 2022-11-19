/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:08:06 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/19 19:42:55 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_map	*map_new(char *content, t_type type)
{
	t_map	*lstnew;

	lstnew = ft_calloc(1, sizeof(t_map *));
	if (!lstnew)
		return (NULL);
	lstnew->content = content;
	lstnew->type = type;
	lstnew->next = NULL;
	return (lstnew);
}
