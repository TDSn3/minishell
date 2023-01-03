/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:42:12 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/03 12:42:41 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	last_cmd(t_input *input, t_list *cmds)
{
	t_list	*nextl;
	size_t	i;

	(void) cmds;
	i = 0;
	nextl = input->ast;
	if (input->ast)
	{
		while (nextl)
		{
			if (nextl == cmds && !nextl->next)
				return (1);
			nextl = nextl->next;
			i++;
		}
	}
	return (0);
}
