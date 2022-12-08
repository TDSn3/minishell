/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_chr_start_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:06:50 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/08 13:51:49 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*																			  */
/*   Cherche strchr au début de str. Si strchr n'est pas imédiatement		  */
/*   trouvé, retounre 0, sinon, retourn 1.									  */
/*																			  */
/* ************************************************************************** */
int	str_chr_start_str(char *str, char *strchr)
{
	int	i;
	int	equal_str;

	i = 0;
	equal_str = 0;
	if (!str || !strchr)
		return (0);
	while (str[i] || strchr[i])
	{
		if (str[i] && !ft_isalnum(str[i]) && str[i] != '_' && str[i] != '=')
			return (0);
		if (str[i] && str[i] == '=')
			equal_str++;
		if ((strchr[i] && !ft_isalnum(strchr[i]) && strchr[i] != '_')
			|| (str[i] && equal_str > 1))
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
		else if (str[i] && str[i] == '=' && equal_str == 1 && !strchr[i])
			return (1);
		else if ((!str[i] && strchr[i]) || (str[i] && !strchr[i]))
			return (0);
		i++;
	}
	if (equal_str < 2)
		return (1);
	return (0);
}
