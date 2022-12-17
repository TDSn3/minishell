/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unquoted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:42:01 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/17 05:09:19 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static char	*extend_line(char *extension, char *line);

char	*unquoted(t_input *input, char *word)
{
	t_type	type;
	char	*q;
	char	*tmp;
	int		count;

	count = 0;
	q = NULL;
	while (word[count])
	{
		type = switch_type(word[count]);
		if (type == DQUOTE || type == SQUOTE)
			tmp = remove_quote_in_word(input, word, type, &count);
		else if (type == DOLLAR)
			tmp = replace_dollar(input, word, &count, type);
		else
			tmp = ft_substr(word, count, 1);
		q = ft_strjoin_free(q, tmp);
		free(tmp);
		count++;
	}
	return (q);
}

char	*remove_quote_in_word(t_input *input,
			char *line, t_type type, int *start)
{
	int		index;
	char	*tmp;

	tmp = NULL;
	index = *start + 1;
	while (line[index] && switch_type(line[index]) != type)
	{
		if (type == DQUOTE && line[index] == '$')
		{
			if (index > *start + 1)
				tmp = extend_line(ft_substr(line, *start, index), tmp);
			tmp = extend_line(replace_dollar(input, line, &index, type), tmp);
			*start = index;
		}
		if (line[index])
			index++;
	}
	if (line[index] && switch_type(line[index]) == type)
		tmp = extend_line(
				ft_substr(line, *start + 1, index - (*start + 1)), tmp);
	*start = index;
	return (tmp);
}

static char	*extend_line(char *extension, char *line)
{
	line = ft_strjoin_free(line, extension);
	free(extension);
	return (line);
}
