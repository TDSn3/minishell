/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:08:30 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/11 11:29:46 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	ms_exit(t_input *input, int exit_status)
{
	ft_putstr_fd("exit\n", 2);
	free_input(input);
	free_all(input);
	exit(exit_status);
}
