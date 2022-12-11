/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:14:19 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/11 14:15:04 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	update_var(char *var, t_input *input)
{
	int		equal;

	if (!my_strcmp(var, get_export(var, input)))
		return (0);
	equal = my_strchr_pos(var, '=');
	if (equal > -1)
		var[equal] = 0;
	if (equal == -1)
		return (0);
	if (ms_unset(var, input))
	{
		if (equal > -1)
			var[equal] = '=';
		return (1);
	}
	if (equal > -1)
		var[equal] = '=';
	if (ms_export(var, input))
		return (1);
	return (0);
}
