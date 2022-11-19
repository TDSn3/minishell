/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:19:08 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/24 20:38:07 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	dl_clear(t_dl **lst)
{
	t_dl	**copydl_one;
	t_dl	*copydl_two;

	copydl_one = lst;
	if (!*lst)
		return ;
	while (*copydl_one)
	{
		copydl_two = (*copydl_one)->next;
		li_clear(&((*copydl_one)->next_li));
		(*copydl_one)->content = -1;
		free(*copydl_one);
		*copydl_one = copydl_two;
	}
	*lst = NULL;
}
