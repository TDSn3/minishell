/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:20:55 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/23 20:27:12 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	remove_last(char **copy)
{
	char	*save;

	save = *copy;
	if ((*copy)[ft_strlen(*copy) - 1] == '/')
	{
		(*copy)[ft_strlen(*copy) - 1] = 0;
		*copy = ft_strdup(*copy);
		if (!*copy)
			return (1);
		free(save);
	}
	return (0);
}
