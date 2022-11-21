/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:48:38 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/21 20:01:17 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	free_input(t_input *input)
{
	free(input->raw);
	map_clear(&input->lexer, free);
	if (input->line)
		free(input->line);
}
