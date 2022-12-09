/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_clear_one_export.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:58:51 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/09 03:59:17 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	content_found_and_del(t_ls **lst, t_ls *ls_cpy, int ls_size_stock);

void	ls_clear_one_export(t_ls **lst, char *content)
{
	t_ls	*ls_cpy;
	int		ls_size_stock;
	int		pos;

	if (!lst || !*lst)
		return ;
	ls_size_stock = ls_size(*lst);
	ls_cpy = *lst;
	while (ls_cpy)
	{
		pos = my_strchr_pos(ls_cpy->content_one, '=');
		if (pos > -1)
			ls_cpy->content_one[pos] = 0;
		if (!my_strcmp(ls_cpy->content_one, content))
		{
			if (pos > -1)
				ls_cpy->content_one[pos] = '=';
			break ;
		}
		if (pos > -1)
			ls_cpy->content_one[pos] = '=';
		ls_cpy = ls_cpy->next;
	}
	if (ls_cpy)
		content_found_and_del(lst, ls_cpy, ls_size_stock);
}

static void	content_found_and_del(t_ls **lst, t_ls *ls_cpy, int ls_size_stock)
{
	if (ls_size_stock == 1)
	{
		ls_clear(lst);
		return ;
	}
	if (ls_cpy->prev)
		ls_cpy->prev->next = ls_cpy->next;
	if (ls_cpy->next)
	{
		ls_cpy->next->prev = ls_cpy->prev;
		if (ls_cpy == *lst)
			*lst = ls_cpy->next;
	}
	free(ls_cpy->content_one);
	free(ls_cpy);
}
