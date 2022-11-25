/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:18:44 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/25 10:04:58 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ls_add_back(t_ls **lst, t_ls *new)
{
	t_ls	*copyl;

	if (!new)
		return (1);
	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			copyl = ls_last(*lst);
			copyl->next = new;
			copyl->next->prev = copyl;
		}
	}
	return (0);
}
