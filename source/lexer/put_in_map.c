/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:21:16 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/12 11:21:47 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	put_in_map(t_input *input, char *line, int count, int start)
{
	if (count > start)
		map_add(&input->lexer,
			map_new(ft_substr(line, start, count), WORD));
}
