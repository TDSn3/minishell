/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:18:52 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/30 20:31:38 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static char	**ft_strdcpy(char **strd);

void	init_input(t_input *input, char *line, char **env)
{
//	input->env = g_d.env;
	input->env = ft_strdcpy(env);
	input->raw = line;
	input->lexer = NULL;
	input->parser = NULL;
	input->ast = NULL;
	input->line = NULL;
}

static char	**ft_strdcpy(char **strd)
{
	char	**newstrd;
	int		count;

	newstrd = (char **) calloc(ft_strdlen(strd) + 1, sizeof(char *));
	if (!strd)
		return (NULL);
	count = 0;
	while (strd[count])
	{
		newstrd[count] = ft_strdup(strd[count]);
		count ++;
	}
	return (newstrd);
}
