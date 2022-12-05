/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:20:55 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/05 17:41:34 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	remove_last(char **copy)
{
	char	*save;
	size_t	size;

	size = ft_strlen(*copy);
	save = *copy;
	if (size > 0 && (*copy)[size - 1] == '/')
	{
		(*copy)[size - 1] = 0;
		*copy = ft_strdup(*copy);
		free(save);
		if (!*copy)
			return (1);
	}
	return (0);
}
