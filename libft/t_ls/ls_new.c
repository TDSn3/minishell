/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/24 13:57:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_ls	*ls_new(char *content_one)
{
	t_ls	*ls;

	ls = malloc(sizeof(t_ls));
	if (!ls)
		return (NULL);
	ls->content_one = content_one;
	ls->next = NULL;
	ls->prev = NULL;
	return (ls);
}
