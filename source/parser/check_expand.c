/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:41:02 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/02 13:16:20 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	check_one_c(char *word, int *i, t_type type);

void	check_expand(t_input *input)
{
	t_map	*tmp;
	char	*s;

	s = NULL;
	tmp = input->lexer;
	while (tmp)
	{
		if (tmp->type == WORD || is_break(tmp->type))
		{
			s = ft_strdup(tmp->content);
			map_add(&input->parser, map_new(s, tmp->type));
		}
		tmp = tmp->next;
	}
}

char	*replace_dollar(t_input *input, char *word, int *start, t_type type)
{
	int		i;
	char	*tmp;
	char	*stock_return;

	tmp = NULL;
	i = *start;
	check_one_c(word, &i, type);
	if (i > *start)
	{
		tmp = ft_substr(word, *start + 1, i - *start);
		*start = i;
		if (tmp && !ft_strncmp("?", tmp, 2))
		{
			free(tmp);
			return (ft_itoa(g_status));
		}
		else if (tmp)
		{
			stock_return = find_in_env(input->env, tmp);
			free(tmp);
			return (stock_return);
		}
	}
	return (ft_strdup("$"));
}

static void	check_one_c(char *word, int *i, t_type type)
{
	while (word[*i] && word[*i + 1])
	{
		if ((switch_type(word[*i + 1]) == type
				|| word[*i + 1] == ' '
				|| word[*i + 1] == '$'
				|| (type == DOLLAR && (word[*i + 1] == '\''
						|| word[*i + 1] == '\"'))))
			return ;
		*i += 1;
	}
}
