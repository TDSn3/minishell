/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:03:29 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/16 16:38:27 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	ft_cmd_error(t_list *cmd, char *message)
{
	t_node	*node;

	if (cmd)
	{
		node = cmd->content;
		ft_putstr_fd(node->args[0], 2);
	}
	if (message)
		perror(message);
	return (0);
}
