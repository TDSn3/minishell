/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_clear_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:58:51 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/24 13:53:28 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ls_clear_one(t_ls **lst, char *content)
{
	t_ls	*ls_cpy;
	int		ls_size_stock;

	ls_size_stock = ls_size(*lst);
	ls_cpy = *lst;
	if (ls_size_stock == 1)
	{
		ls_clear(lst);
		return ;
	}	
	while (ls_cpy && my_strcmp(ls_cpy->content_one, content))
		ls_cpy = ls_cpy->next;
	if (!(my_strcmp(ls_cpy->content_one, content)))
	{
		if (ls_cpy->prev)
			ls_cpy->prev->next = ls_cpy->next;
		if (ls_cpy->next)
		{
			ls_cpy->next->prev = ls_cpy->prev;
			if (ls_cpy == *lst)
				*lst = ls_cpy->next;
		}
		free(ls_cpy);
	}
}
