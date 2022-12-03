/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:48:38 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/02 14:31:58 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	ft_freenode(void *n);

void	free_input(t_input *input)
{
//	ft_strdfree(input->env);
	free(input->raw);
	map_clear(&input->lexer, free);
	map_clear(&input->parser, free);
	ft_lstiter(input->ast, &ft_freenode);
	ft_lstclear(&input->ast, free);
	if (input->line)
		free(input->line);
}

static void	ft_freenode(void *n)
{
	int		count;
	t_node	*node;

	count = 0;
	node = (t_node *) n;
	if (node->file)
		free(node->file);
	while (node->args && node->args[count])
		free(node->args[count++]);
	free(node->args);
}
