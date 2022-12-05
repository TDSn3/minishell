/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:51:25 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/05 18:31:02 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	free_all_here(
					char *save,
					char *stock_one,
					char *stock_two,
					char *stock_three);

int	one_point(char **copy, int i)
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
	stock_two = ft_substr(*copy, 0, i - ft_strlen(ft_strrchr(stock_one, '/')));
	if (!stock_two)
		return (free_all_here(save, stock_one, stock_two, stock_three));
	if (i + 1 <= (int)ft_strlen(*copy))
		stock_three = ft_substr(*copy, i + 1, ft_strlen(*copy + (i + 1)));
	else
		stock_three = ft_substr(*copy, i + 1, 0);
	if (!stock_three)
		return (free_all_here(save, stock_one, stock_two, stock_three));
	save = *copy;
	*copy = ft_strjoin(stock_two, stock_three);
	if (!*copy)
		return (free_all_here(save, stock_one, stock_two, stock_three));
	free_all_here(save, stock_one, stock_two, stock_three);
	return (0);
}

static int	free_all_here(
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
