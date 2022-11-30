/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:37:26 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/30 00:37:38 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	ft_strdfree(char **strd)
{
	int	count;

	count = 0;
	while (strd[count])
	{
		free(strd[count]);
		count ++;
	}
	free(strd);
}
