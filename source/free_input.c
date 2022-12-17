/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:48:38 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/15 14:14:26 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	ft_freenode(void *n);
static void	ft_freeredir(void *r);

void	free_input(t_input *input)
{
	if (input->raw)
		free(input->raw);
	if (input->fdin > 0)
		close(input->fdin);
	if (input->fdout > 2)
		close(input->fdout);
	map_clear(&input->lexer, free);
	map_clear(&input->parser, free);
	ft_lstiter(input->ast, &ft_freenode);
	ft_lstclear(&input->ast, free);
	if (input->pids)
		free(input->pids);
}

static void	ft_freenode(void *n)
{
	int		count;
	t_node	*node;

	count = 0;
	node = (t_node *) n;
	while (node->args && node->args[count])
		free(node->args[count++]);
	free(node->args);
	ft_lstiter(node->redir, &ft_freeredir);
	ft_lstclear(&node->redir, free);
}

static void	ft_freeredir(void *r)
{
	t_redir	*redir;

	redir = (t_redir *) r;
	if (redir->file)
		free(redir->file);
	redir->file = NULL;
}
