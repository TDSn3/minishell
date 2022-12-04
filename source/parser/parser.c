/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:19:45 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/04 16:55:11 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static t_node	*new_node(void);
static int		set_redir(t_type type);

void	parser(t_input *input)
{
	t_map	*tmp;
	t_node	*node;

	tmp = input->parser;
	ft_lstadd_back(&input->ast, ft_lstnew(new_node()));
	while (tmp)
	{
		if (tmp->type == WORD)
		{
			node = ft_lstlast(input->ast)->content;
			node->args = ft_strdjoin(node->args, tmp->content);
		}
		else if (tmp->type == PIPE)
			ft_lstadd_back(&input->ast, ft_lstnew(new_node()));
		else if (is_break(tmp->type))
		{
			node = ft_lstlast(input->ast)->content;
			node->status = set_redir(tmp->type);
			node->file = ft_streplace(node->file,
					ft_strdup(tmp->next->content));
			tmp = tmp->next;
		}
		tmp = tmp->next;
	}
}

static t_node	*new_node(void)
{
	t_node	*node;

	node = (t_node *) ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->status = 0;
	return (node);
}

static int	set_redir(t_type type)
{
	if (type == GREDIR)
		return (1);
	if (type == GRREDIR)
		return (11);
	if (type == DREDIR)
		return (2);
	if (type == DRREDIR)
		return (22);
	return (0);
}
