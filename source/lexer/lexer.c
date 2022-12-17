/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:50:14 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/17 04:23:53 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	split_redir(t_input *input, char *line, int index, t_type *type);
static int	in_the_while(t_input *input, char *line, t_type	*type, int *start);

int	lexer(t_input *input, char *line)
{
	int		start;
	t_type	type;

	start = 0;
	return (in_the_while(input, line, &type, &start));
}

static int	in_the_while(t_input *input, char *line, t_type	*type, int *start)
{
	int		count;

	count = 0;
	while (line[count])
	{
		*type = switch_type(line[count]);
		if (*type == SQUOTE || *type == DQUOTE || *type == DOLLAR)
		{
			p_iii(input, type, &count, line);
			if (count < 0)
				return (0);
		}
		else if (*type != WORD)
		{
			split_delim(input, start, count, *type);
			if (*type == GREDIR || *type == DREDIR)
				count += split_redir(input, line, count, type);
			if (count < 0)
				return (0);
			*start = count + 1;
		}
		count += !!line[count];
	}
	put_in_map(input, line, count, *start);
	return (1);
}

static int	split_redir(t_input *input, char *line, int index, t_type *type)
{
	int	status;
	int	count;

	status = 0;
	count = index;
	while (line[count] && line[++count] == line[index])
		status ++;
	if (status > 1)
	{
		lexer_char_error(input,
			"error syntaxe unexpected token : `, ", line[index]);
		return ((index + 1) * (-1));
	}
	if (status > 0)
	{
		free(map_last(input->lexer)->content);
		if (*type == GREDIR)
			map_last(input->lexer)->type = GRREDIR;
		if (*type == DREDIR)
			map_last(input->lexer)->type = DRREDIR;
		(map_last(input->lexer))->content = ft_substr(line, index, 2);
	}
	return (status);
}
