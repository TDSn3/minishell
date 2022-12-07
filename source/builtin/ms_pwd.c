/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:58:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/07 20:54:44 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	ms_pwd(t_input *input)
{
	char	*pwd;

	pwd = ms_get_env("PWD", input);
	if (!pwd || !*pwd || !*(pwd + 1))
	{
		perror("pwd");
		return (1);
	}
	printf("%s\n", pwd + 1);
	return (0);
}
