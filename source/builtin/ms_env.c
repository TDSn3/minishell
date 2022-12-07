/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:29:00 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/07 15:56:37 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	ms_env(t_input *input)
{
	int		i;

	i = 0;
	if (input->env)
		while ((input->env)[i])
			printf("%s\n", (input->env)[i++]);
	return (0);
}

/*	Avec de la couleur
	int		pos;
	char	*after_equal;

	if (input->env && *(input->env) && **(input->env))
	{
		while (input->env[i])
		{
			after_equal = ft_strchr(input->env[i], '=');
			if (after_equal)
				after_equal += 1;
			pos = my_strchr_pos(input->env[i], '=');
			if (pos > -1)
			{
				input->env[i][pos] = 0;
				printf("\033[36;01m%s\033[37;00m=", input->env[i]);
				input->env[i][pos] = '=';
				printf("\033[33m%s\033[00m\n", after_equal);
			}
			else
				printf("\033[36;01m%s\033[37;00m=", input->env[i]);
			i++;
		}
	}
*/