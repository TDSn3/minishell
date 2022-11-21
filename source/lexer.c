/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:50:14 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/20 10:34:24 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static char	*search(char *line, int *start);
static bool	is_delim(char c);

void	lexer(t_input *input, char *line)
{
	int		count;
	int		start;
	char	c;

	count = 0;
	start = 0;
	while (line[count])
	{
		c = line[count];
		if (is_delim(c))
		{
			map_add(&input->lexer,
				map_new(ft_substr(line, start, count - start), WORD));
			map_add(&input->lexer,
				map_new(ft_substr(line, count, 1), DELIM));
			start = count + 1;
		}
		if (c == '\'' || c == '\"')
		{
			if (count - start > 0)
				map_add(&input->lexer,
					map_new(ft_substr(line, start, count - start), WORD));
			if (c == '\'')
				map_add(&input->lexer, map_new(search(line, &count), SQUOTE));
			else if (c == '\"')
				map_add(&input->lexer, map_new(search(line, &count), DQUOTE));
			start = count + 1;
		}
		count ++;
	}
}

static char	*search(char *line, int *start)
{
	int		count;
	char	*s;
	char	c;

	count = *start;
	c = line[*start];
	while (line[++count])
	{
		if (c == line[count])
			break ;
	}
	if (line[count] != c)
	{
		ft_putstr_fd("Error : unclosed quote\n", 2);
		exit(1);
	}
	s = ft_substr(line, *start, count - *start + 1);
	*start = count;
	return (s);
}

static bool	is_delim(char c)
{
	if (c == ' ' || c == '\n' || c == '|' || c == '<' || c == '>' || c == '$')
		return (true);
	return (false);
}
 