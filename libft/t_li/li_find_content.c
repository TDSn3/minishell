/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_find_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:06:48 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/10 10:43:31 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	li_find_content(t_li *lst, int content)
{
	t_li	*nextl;
	size_t	i;

	i = 0;
	nextl = lst;
	if (!lst)
		return (0);
	while (nextl)
	{
		if (nextl->content_one == content)
			return (content);
		nextl = nextl->next;
		i++;
	}
	return (0);
}
