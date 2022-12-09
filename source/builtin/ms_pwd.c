/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:58:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/09 00:08:45 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	ms_pwd(t_input *input)
{
	char	*pwd;

	pwd = ms_get_env("PWD", input);
	if (!pwd || !*pwd)
		return (1);
	printf("%s\n", pwd);
	return (0);
}
