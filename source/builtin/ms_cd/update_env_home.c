/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env_home.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:08:39 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/12 18:33:49 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	update_env_home(const char *str, t_input *input)
{
	char	*stock;

	stock = ft_strjoin("PWD=", str);
	if (ms_export(stock, input))
	{
		free(stock);
		return (1);
	}
	free(stock);
	return (0);
}
