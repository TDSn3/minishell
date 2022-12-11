/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_chr_start_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:06:50 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/11 18:13:54 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	check_all_c(char *str, char *strchr, int *equal_str);
static int	name_var_is_ok(char *str, char *strchr, int *equal_str, int i);

/* ************************************************************************** */
/*																			  */
/*   Cherche strchr au début de str. Si strchr n'est pas imédiatement		  */
/*   trouvé, return 0, sinon, return 1.										  */
/*																			  */
/* ************************************************************************** */
int	str_chr_start_str(char *str, char *strchr)
{
	int	stock;
	int	equal_str;

	equal_str = 0;
	if (!str || !strchr)
		return (0);
	stock = check_all_c(str, strchr, &equal_str);
	if (stock != -1)
		return (stock);
	if (equal_str < 2)
		return (1);
	return (0);
}

static int	check_all_c(char *str, char *strchr, int *equal_str)
{
	int	i;

	i = 0;
	while (str[i] || strchr[i])
	{
		if (!name_var_is_ok(str, strchr, equal_str, i))
			return (0);
		if (str[i] && strchr[i])
		{
			if (str[i] == strchr[i])
			{
				i++;
				continue ;
			}
			else
				return (0);
		}
		else if (str[i] && str[i] == '=' && *equal_str == 1 && !strchr[i])
			return (1);
		else if ((!str[i] && strchr[i]) || (str[i] && !strchr[i]))
			return (0);
		i++;
	}
	return (-1);
}

static int	name_var_is_ok(char *str, char *strchr, int *equal_str, int i)
{
	if (str[i] && !ft_isalnum(str[i]) && str[i] != '_' && str[i] != '=')
		return (0);
	if (str[i] && str[i] == '=')
		*equal_str += 1;
	if ((strchr[i] && !ft_isalnum(strchr[i]) && strchr[i] != '_')
		|| (str[i] && *equal_str > 1))
		return (0);
	return (1);
}
