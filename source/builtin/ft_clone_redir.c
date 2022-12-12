/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clone_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:28:30 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/12 21:29:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	ft_clone_redir(t_list *r, int *fd)
{
	t_redir	*redir;
	int		fdin;
	int		fdout;

	fdin = 0;
	fdout = 0;
	while (r)
	{
		redir = r->content;
		if (!fdin && (redir->type == 1 || redir->type == 11))
		{
			fd[0] = dup(STDIN_FILENO);
			fdin = 1;
		}
		else if (!fdout && (redir->type == 2 || redir->type == 22))
		{
			fd[1] = dup(STDOUT_FILENO);
			fdout = 1;
		}
		if (fdin > 0 && fdout > 0)
			break ;
		else
			r = r->next;
	}
}
