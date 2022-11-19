/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:18:52 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/19 18:04:17 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	init_input(t_input *input, char *line, char ***env)
{
	input->env = *env;
	input->raw = line;
	input->line = NULL;
	input->lexer = NULL;
}
