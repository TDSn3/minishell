/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bultin_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:42:19 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/04 17:53:51 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	print_error(char *cmd, int nb_error);

void	exit_bultin_util(t_node *node, t_input *input)
{
	size_t	size_argv;

	size_argv = my_strdlen(node->args);
	if (size_argv > 2)
		print_error(node->args[0], -1);
	else if (node->args && node->args[0]
		&& !my_str_isdigit(node->args[1]) && ft_atoi(node->args[1]) == 0)
	{
		print_error(node->args[0], -2);
		ms_exit(input, ft_atoi(node->args[1]));
	}
	else
		ms_exit(input, ft_atoi(node->args[1]));
}

static int	print_error(char *cmd, int nb_error)
{
	if (nb_error == -1)
		ft_putstr_fd("too many arguments\n", 2);
	else if (nb_error == -2)
		ft_putstr_fd("exit: numeric argument required\n", 2);
	else
	{
		errno = nb_error;
		perror("export");
	}
	g_status = 1;
	(void) cmd;
	return (1);
}
