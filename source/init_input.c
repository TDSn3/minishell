/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:18:52 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/07 15:24:23 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

//static char	**ft_path(void);

void	init_input(t_input *input, char *line)
{
	input->env = NULL;
	input->export = NULL;
//	input->paths = ft_path();
	input->raw = line;
	input->lexer = NULL;
	input->parser = NULL;
	input->ast = NULL;
	input->line = NULL;
}

//static char	**ft_path(void)
//{
//	char	**all_path;
//
//	all_path = ft_split(ms_get_env("PATH") + 1, ':');
//	if (all_path)
//		return (all_path);
//	return (NULL);
//}
