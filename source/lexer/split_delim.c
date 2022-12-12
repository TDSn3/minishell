/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_delim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:02:21 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/12 20:03:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	split_delim(t_input *input, int *start, int index, t_type type)
{
	int		r;
	char	*line;

	r = index - *start;
	line = input->raw;
	if (r > 0)
		map_add(&input->lexer, map_new(ft_substr(line, *start, r), WORD));
	if (type != ESPACE)
		map_add(&input->lexer, map_new(ft_substr(line, index, 1), type));
	*start = index + 1;
}
