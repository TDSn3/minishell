/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_name_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:34:31 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/24 19:49:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>


int	wrong_name_var(char *var)
{
	int	equal;
	int	i;

	i = 0;
	equal = my_strchr_pos(var, '=');
	if (equal > -1)
		var[equal] = 0;
	if (equal == 0)
		return (1);
	while (var[i])
	{
		if (!ft_isalnum(var[i]) && var[i] != '_')
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

