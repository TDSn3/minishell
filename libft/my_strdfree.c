/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strdfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:47:00 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/10 20:51:54 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_strdfree(char ***strd)
{
	int	i;

	i = 0;
	if (strd && *strd && **strd)
		while ((*strd)[i])
			free((*strd)[i++]);
	if (strd && *strd)
		free(*strd);
	return (1);
}
