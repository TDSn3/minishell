/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:44:32 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/03 15:46:54 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	chech_d_redir(t_map *tmp);

int	check_next_redir(t_map *tmp)
{
	if (tmp->type == GREDIR)
	{
		if ((tmp->next) && tmp->next->type == DREDIR)
		{
			ft_putstr_fd("syntax error near unexpected token `>'\n", 2);
			return (1);
		}
		if ((tmp->next) && tmp->next->type == GREDIR)
		{
			ft_putstr_fd("syntax error near unexpected token `<'\n", 2);
			return (1);
		}
	}
	if (chech_d_redir(tmp))
		return (1);
	if (tmp->type == PIPE)
	{
		if ((tmp->next) && tmp->next->type == PIPE)
		{
			ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
			return (1);
		}
	}
	return (0);
}

static int	chech_d_redir(t_map *tmp)
{
	if (tmp->type == DREDIR)
	{
		if ((tmp->next) && tmp->next->type == DREDIR)
		{
			ft_putstr_fd("syntax error near unexpected token `>'\n", 2);
			return (1);
		}
		if ((tmp->next) && tmp->next->type == GREDIR)
		{
			ft_putstr_fd("syntax error near unexpected token `<'\n", 2);
			return (1);
		}
	}
	return (0);
}
