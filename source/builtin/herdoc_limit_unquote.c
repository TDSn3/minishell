/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_limit_unquote.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 08:25:00 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/04 08:59:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	quote_to_zero(char *str, int size);
static void	remove_zero(char *str, int size);
static int	skip_zero(char *str, int *i);

char	*herdoc_limit_unquote(char *str)
{
	int		i;
	int		size;
	char	*new_str;
	char	*save_for_free;

	i = 0;
	new_str = NULL;
	if (!str)
		return (NULL);
	size = ft_strlen(str);
	quote_to_zero(str, size);
	while (i < size)
	{
		if (skip_zero(str, &i))
			continue ;
		save_for_free = new_str;
		new_str = ft_strjoin(new_str, str + i);
		if (save_for_free)
			free(save_for_free);
		i += ft_strlen(str + i);
	}
	remove_zero(str, size);
	return (new_str);
}

static int	skip_zero(char *str, int *i)
{
	if (!str[*i])
	{
		*i += 1;
		return (1);
	}
	else
		return (0);
}

static void	quote_to_zero(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] == '\'')
		{
			str[i] = '\0';
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			str[i] = '\0';
		}
		else if (str[i] == '\"')
		{
			str[i] = '\0';
			i++;
			while (str[i] && str[i] != '\"')
				i++;
			str[i] = '\0';
		}
		else
			i++;
	}
}

static void	remove_zero(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!str[i])
		{
			str[i] = 'a';
			i++;
			continue ;
		}
		i++;
	}
	free(str);
}

/*
static void	quote_to_zero(char *str, int size);
static void	join_unquote(char *str, char *new_str, int size);

char	*herdoc_limit_unquote(char *str)
{
	int		i;
	int		size;
	char	*new_str;

	i = 0;
	new_str = NULL;
	if (!str)
		return (NULL);
	size = ft_strlen(str);
	quote_to_zero(str, size);
	join_unquote(str, new_str, size);
	i = 0;
	while (i < size)
	{
		if (!str[i])
		{
			str[i] = 'a';
			i++;
			continue ;
		}
		i++;
	}
	free(str);
	return (new_str);
}

static void	quote_to_zero(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] == '\'')
		{
			str[i] = '\0';
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			str[i] = '\0';
		}
		else if (str[i] == '\"')
		{
			str[i] = '\0';
			i++;
			while (str[i] && str[i] != '\"')
				i++;
			str[i] = '\0';
		}
		else
			i++;
	}
}

static void	join_unquote(char *str, char *new_str, int size)
{
	int		i;
	char	*save_for_free;

	i = 0;
	while (i < size)
	{
		if (!str[i])
		{
			i++;
			continue ;
		}
		save_for_free = new_str;
		new_str = ft_strjoin(new_str, str + i);
		if (save_for_free)
			free(save_for_free);
		i += ft_strlen(str + i);
	}
}

*/