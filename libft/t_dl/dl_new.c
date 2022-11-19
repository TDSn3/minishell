/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/10 19:51:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_dl	*dl_new(int content)
{
	t_dl	*new_dl;
	t_li	*new_li;

	new_dl = malloc(sizeof(t_dl));
	if (!new_dl)
		return (NULL);
	new_li = li_new(-1, -1);
	if (!new_li)
		return (NULL);
	new_dl->next_li = new_li;
	new_dl->content = content;
	new_dl->next = NULL;
	new_dl->prev = NULL;
	new_dl->prev_li = NULL;
	return (new_dl);
}
