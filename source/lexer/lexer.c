/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:50:14 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/07 20:24:39 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	split_delim(t_input *input, int *start, int index, t_type type);
static int	split_dollar(t_input *input, int *start, int index, t_type type);
static int	split_redir(t_input *input, char *line, int index, t_type *type);
static int	split_quote(t_input *input, char *line, int index, t_type type);

void	lexer(t_input *input, char *line)
{
	int		count;
	int		start;
	t_type	type;

	count = 0;
	start = 0;
	while (line[count])
	{
		type = switch_type(line[count]);
		if (type != WORD)
		{
			split_delim(input, &start, count, type);
			if (type == DOLLAR)
				count = split_dollar(input, &start, count, type);
			if (type == GREDIR || type == DREDIR)
				count += split_redir(input, line, count, &type);
			if (type == SQUOTE || type == DQUOTE)
				count = split_quote(input, line, count, type);
			start = count + 1;
		}
		count ++;
	}
	if (count > start)
		map_add(&input->lexer,
			map_new(ft_substr(line, start, count), WORD));
}

static void	split_delim(t_input *input, int *start, int index, t_type type)
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

static int	split_dollar(t_input *input, int *start, int index, t_type type)
{
	int		r;
	int		count;
	char	*line;

	count = index + 1;
	line = input->raw;
	while (line[count] && line[count] != ' ')
	{
		if (switch_type(line[count]) == type)
			return (index);
		count ++;
	}
	if (line[count] == ' ')
	{
		r = count - *start;
		type = switch_type(line[count - 1]);
		if (!is_break(type))
			type = WORD;
		map_add(&input->lexer, map_new(ft_substr(line, *start, r), type));
		*start = count;
		return (count);
	}
	return (index);
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
		exit (0);
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

static int	split_quote(t_input *input, char *line, int index, t_type type)
{
	int		start;
	char	c;

	c = line[index];
	start = index + 1;
	while (line[index] && line[++index] != c)
	{
		if (c == '\"')
		{
			if (line[index] == '$')
			{
				split_delim(input, &start, index, DOLLAR);
				index = split_dollar(input, &start, index, type);
			}
		}
	}
	if (line[index] != c)
	{
		lexer_char_error(input, "error syntaxe unexpected token : ` ", c);
	}
	split_delim(input, &start, index, type);
	return (index);
}

/*
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
*/
