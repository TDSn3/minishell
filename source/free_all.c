/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:56:49 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/12 17:27:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	free_all(t_input *input)
{
	int	i;

	i = 0;
	if (input->env && *(input->env))
		while ((input->env)[i])
			free((input->env)[i++]);
	if (input->env)
		free(input->env);
	ls_clear(&(input->export));
	rl_clear_history();
	return (0);
}
