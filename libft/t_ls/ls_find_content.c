/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_find_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:06:48 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/24 13:58:39 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ls_find_content(t_ls *lst, char *content)
{
	t_ls	*nextl;
	size_t	i;

	i = 0;
	nextl = lst;
	if (!lst)
		return (0);
	while (nextl)
	{
		if (!(my_strcmp(nextl->content_one, content)))
			return (content);
		nextl = nextl->next;
		i++;
	}
	return (0);
}
