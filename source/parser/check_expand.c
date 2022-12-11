/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:41:02 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/11 01:32:51 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static char	*remove_quote(t_input *input, t_map **map, t_type type);
static char	*expand_dollar(t_input *input, t_map **map);
static char	*find_in_env(char **env, char *var);
static bool	ft_findstr(char *str, const char *find);

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
		else
		{
			if (tmp->type == DOLLAR)
				s = expand_dollar(input, &tmp);
			if (tmp->type == SQUOTE || tmp->type == DQUOTE)
				s = remove_quote(input, &tmp, tmp->type);
			map_add(&input->parser, map_new(s, WORD));
		}
		tmp = tmp->next;
	}
}

static char	*remove_quote(t_input *input, t_map **map, t_type type)
{
	t_map	*tmp;
	char	*s;
	char	*d;

	tmp = (*map)->next;
	s = NULL;
	while (tmp && tmp->type != type)
	{
		if (tmp->type == DOLLAR)
		{
			if (tmp->next && tmp->next->type == type)
				d = ft_strdup("$");
			else
				d = expand_dollar(input, &tmp);
			s = ft_strjoin_free(s, d);
			free(d);
		}
		else
			s = ft_strjoin_free(s, tmp->content);
		tmp = tmp->next;
	}
	*map = tmp;
	return (s);
}

static char	*expand_dollar(t_input *input, t_map **map)
{
	t_map	*tmp;

	tmp = (*map)->next;
	if (tmp)
	{
		*map = tmp;
		if (tmp->type == WORD && ft_strlen(tmp->content) > 0)
			return (find_in_env(input->env, tmp->content));
		if (is_break(tmp->type))
			return (ft_strjoin("$", tmp->content));
	}
	return (ft_strdup("$"));
}

static char	*find_in_env(char **env, char *var)
{
	int	count;

	count = 0;
	while (env[count])
	{
		if (ft_findstr(env[count], var))
			return (ft_substr(env[count],
					ft_strlen(var) + 1, ft_strlen(env[count])));
		count ++;
	}
	return (ft_strdup(""));
}

static bool	ft_findstr(char *str, const char *find)
{
	size_t	len;

	len = ft_strlen(find);
	if (ft_strncmp(str, find, len))
		return (false);
	if (str[len] != '=')
		return (false);
	return (true);
}
