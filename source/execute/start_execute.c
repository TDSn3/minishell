/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:55:33 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/30 16:59:13 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	start_execute(t_input *input)
{
	t_list	*cmds;
	size_t	size;

	cmds = input->ast;
	size = ft_lstsize(cmds);
	if (size == 1)
		check_cmd(input, cmds);
	else if (size > 1)
	{
		input->pids = (int *) ft_calloc(size, sizeof(int));
		if (!input->pids)
			return ;
		exec_pipe(input, cmds, size);
	}
	return ;
}
