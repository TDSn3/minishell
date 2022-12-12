/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:48:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/12 13:49:46 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	execute_cmd(t_input *input)
{
	t_list	*cmds;
	size_t	size;

	cmds = input->ast;
	size = ft_lstsize(cmds);
	if (size == 1)
		execute_one_cmd(input, cmds);
	else if (size > 1)
		ms_pipe(input, cmds, size);
	else
		return ;
}
