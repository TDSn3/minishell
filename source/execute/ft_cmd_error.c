/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:03:29 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/10 22:04:01 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	ft_cmd_error(t_input *input, t_list *cmd, char *message)
{
	t_node	*node;

	if (cmd)
	{
		node = cmd->content;
		printf("%s", node->args[0]);
	}
	if (message)
		perror(message);
	(void) input;
	return (0);
}
