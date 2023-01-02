/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:50:14 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/31 14:17:34 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	split_redir(t_input *input, char *line, int index, t_type *type);
static int	in_the_while(t_input *input, char *line, t_type	*type, int *start);

/* ************************************************************************** */
/*																			  */
/*   t_type																	  */
/*																			  */
/*   WORD	 																  */
/*   SQUOTE	 : '															  */
/*   DQUOTE	 : "															  */
/*   DOLLAR	 : $															  */
/*   PIPE	 : |															  */
/*   ESPACE	   																  */
/*   DREDIR	 : >															  */
/*   DRREDIR : >>															  */
/*   GREDIR	 : <															  */
/*   GRREDIR : <<															  */
/*																			  */
/* ************************************************************************** */
int	lexer(t_input *input, char *line)
{
	int		start;
	t_type	type;

	start = 0;
	return (in_the_while(input, line, &type, &start));
}

static int	in_the_while(t_input *input, char *line, t_type	*type, int *start)
{
	int		i;

	i = 0;
	while (line[i])
	{
		*type = switch_type(line[i]);
		if (*type == SQUOTE || *type == DQUOTE || *type == DOLLAR)
		{
			p_iii(input, type, &i, line);
			if (i < 0)
				return (0);
		}
		else if (*type != WORD)
		{
			split_delim(input, start, i, *type);
			if (*type == GREDIR || *type == DREDIR)
				i += split_redir(input, line, i, type);
			if (i < 0)
				return (0);
			*start = i + 1;
		}
		i += !!line[i];
	}
	put_in_map(input, line, i, *start);
	return (1);
}

static int	split_redir(t_input *input, char *line, int index, t_type *type)
{
	int	status;
	int	i;

	status = 0;
	i = index;
	while (line[i] && line[++i] == line[index])
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
