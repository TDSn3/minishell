/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:18:28 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/23 20:29:34 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	one_point(char **copy, int i);
static int	two_point(char **copy, int i);
static int	find_point(char **copy);
static int	free_all(
				char *save,
				char *stock_one,
				char *stock_two,
				char *stock_three);

/* ************************************************************************** */
/*																			  */
/*   Supprime les ".." ou les "." du path de cd et supprime leurs			  */
/*   répertoires antérieurs.												  */
/*																			  */
/* ************************************************************************** */
char	*remove_point(char *str)
{
	int		size;
	char	*copy;
	char	*save;

	save = NULL;
	copy = ft_strdup(str);
	size = ft_strlen(copy);
	if (!copy || find_point(&copy))
		return (NULL);
	if (copy[size - 1] == '/' && size > 5)
	{
		save = copy;
		copy = ft_substr(copy, 0, size - 1);
		free(save);
	}
	free(str);
	return (copy);
}

static int	find_point(char **copy)
{
	int		i;

	i = 0;
	while ((*copy)[i])
	{
		if ((*copy)[i] == '.')
		{
			i++;
			if ((*copy)[i] == '.' && (!((*copy)[i + 1])
				|| (*copy)[i + 1] == '/'))
			{
				if (two_point(copy, i))
					return (1);
			}
			else if (!((*copy)[i]) || (*copy)[i] == '/')
				if (one_point(copy, i))
					return (1);
			i = 0;
			continue ;
		}
		i++;
	}
	if (ft_strlen(*copy) > 1 && remove_last(copy))
		return (1);
	return (0);
}

static int	free_all(
					char *save,
					char *stock_one,
					char *stock_two,
					char *stock_three)
{
	if (save)
		free(save);
	if (stock_one)
		free(stock_one);
	if (stock_two)
		free(stock_two);
	if (stock_three)
		free(stock_three);
	return (1);
}

static int	two_point(char **copy, int i)
{
	char	*save;
	char	*stock_one;
	char	*stock_two;
	char	*stock_three;

	save = NULL;
	stock_one = NULL;
	stock_two = NULL;
	stock_three = NULL;
	stock_one = ft_substr(*copy, 0, i - 2);
	if (!stock_one)
		return (1);
	stock_two = ft_substr(*copy, 0, (i - 1) - ft_strlen(
				ft_strrchr(stock_one, '/')));
	if (!stock_two)
		return (free_all(save, stock_one, stock_two, stock_three));
	stock_three = ft_substr(*copy, i + 2, ft_strlen(*copy + (i + 2)));
	if (!stock_three)
		return (free_all(save, stock_one, stock_two, stock_three));
	save = *copy;
	*copy = ft_strjoin(stock_two, stock_three);
	if (!*copy)
		return (free_all(save, stock_one, stock_two, stock_three));
	free_all(save, stock_one, stock_two, stock_three);
	return (0);
}

static int	one_point(char **copy, int i)
{
	char	*save;
	char	*stock_one;
	char	*stock_two;
	char	*stock_three;

	save = NULL;
	stock_one = NULL;
	stock_two = NULL;
	stock_three = NULL;
	stock_one = ft_substr(*copy, 0, i - 1);
	if (!stock_one)
		return (1);
	stock_two = ft_substr(*copy, 0, i - ft_strlen(
				ft_strrchr(stock_one, '/')));
	if (!stock_two)
		return (free_all(save, stock_one, stock_two, stock_three));
	stock_three = ft_substr(*copy, i + 1, ft_strlen(*copy + (i + 1)));
	if (!stock_three)
		return (free_all(save, stock_one, stock_two, stock_three));
	save = *copy;
	*copy = ft_strjoin(stock_two, stock_three);
	if (!*copy)
		return (free_all(save, stock_one, stock_two, stock_three));
	free_all(save, stock_one, stock_two, stock_three);
	return (0);
}
