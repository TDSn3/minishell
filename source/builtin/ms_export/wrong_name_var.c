/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_name_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:34:31 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/16 01:13:53 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	all_digit(char *var);
static int	equal_chr(char *var, int equal);

int	wrong_name_var(char *var)
{
	int	equal;
	int	i;

	i = 0;
	equal = my_strchr_pos(var, '=');
	if (equal_chr(var, equal))
		return (1);
	if (all_digit(var))
		return (1);
	while (var[i])
	{
		if ((!ft_isalnum(var[i]) && var[i] != '_')
			|| (var[0] != '_' && !ft_isalpha(var[0])))
		{
			if (equal > -1)
				var[equal] = '=';
			return (1);
		}
		i++;
	}
	if (equal > -1)
		var[equal] = '=';
	return (0);
}

static int	all_digit(char *var)
{
	int	i;

	i = 0;
	while (var[i] && ft_isdigit(var[i]))
		i++;
	if (i > 0 && !var[i])
		return (1);
	return (0);
}

static int	equal_chr(char *var, int equal)
{
	if (equal > -1)
		var[equal] = 0;
	if (equal == 0)
	{
		var[equal] = '=';
		return (1);
	}
	return (0);
}
