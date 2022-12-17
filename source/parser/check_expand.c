/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:41:02 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/17 05:07:21 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

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
	int		count;
	char	*tmp;

	tmp = NULL;
	count = *start;
	while (word[count] && word[count + 1])
	{
		if ((switch_type(word[count + 1]) == type
				|| word[count + 1] == ' '
				|| word[count + 1] == '$'
				|| (type == DOLLAR && (word[count + 1] == '\''
						|| word[count + 1] == '\"'))))
			break ;
		count++;
	}
	if (count > *start)
	{
		tmp = ft_substr(word, *start + 1, count - *start);
		*start = count;
		if (tmp && !ft_strncmp("?", tmp, 2))
			return (ft_itoa(g_status));
		else if (tmp)
			return (find_in_env(input->env, tmp));
	}
	return (ft_strdup("$"));
}
