/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_iii.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:19:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/17 04:24:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	split_dollar(t_input *input, int index);
static int	split_quote(t_input *input, char *line, int index);

void	p_iii(t_input *input, t_type *type, int *count, char *line)
{
	if (*type == DOLLAR)
		*count = split_dollar(input, *count);
	else
		*count = split_quote(input, line, *count);
}

static int	split_quote(t_input *input, char *line, int index)
{
	char	c;

	c = line[index];
	index++;
	while (line[index] && line[index] != c)
		index++;
	if (line[index] != c)
		return (lexer_char_error(input,
				"error syntaxe unexpected token : ` ", c));
	return (index);
}

static int	split_dollar(t_input *input, int index)
{
	int		count;
	char	*line;

	count = index;
	line = input->raw;
	while (line[count] && line[count + 1])
	{
		if (switch_type(line[count + 1]) != WORD)
			break ;
		count ++;
	}
	if (line[count + 1] == '$' && count == index)
		return (lexer_char_error(input,
				"error syntaxe unexpected token : ` ", line[count]));
	return (count);
}
