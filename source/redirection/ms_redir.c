/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:18:20 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/10 14:22:23 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	ms_redir(t_input *input)
{
	t_list	*ast;
	t_node	*node;
	int		todup;

	ast = input->ast;
	todup = 1;
	while (ast)
	{
		node = ast->content;
		if (!node->args || !node->args[0])
			todup = 0;
		if (!ft_redirect(input, node, todup))
			return ;
		ast = ast->next;
	}
}

static int	ft_redirect(t_input *input, t_node *node, int todup)
{
	t_redir	*redir;
	t_list	*r;
	int	res;

	res = 1;
	r = node->redir;
	while (r)
	{
		redir = r->content;
		if (redir->type == 1)
			res = g_redir(input, redir, 0, todup);
		if (redir->type == 11)
			res = g_redir(input, redir, 1, todup);
		if (redir->type == 2)
			res = d_redir(input, redir->file, 0, todup);
		if (redir->type == 22)
			res = d_redir(input, redir->file, 1, todup);
		if (res != 1)
		{
			perror("redirection ");
			return (0);
		}
		r = r->next;
	}
	return (1);
}
