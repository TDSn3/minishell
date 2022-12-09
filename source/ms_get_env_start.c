/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_env_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:42:02 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/09 02:09:27 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*																			  */
/*   Similaire à ft_get_env, mais renvois un double pointeur de toute 		  */
/*   la ligne.											  					  */
/*																			  */
/* ************************************************************************** */
char	**ms_get_env_start(char *strchr, t_input *input)
{
	int	i;

	i = 0;
	if (!input->env)
		return (NULL);
	while ((input->env)[i])
	{
		if (str_chr_start_str((input->env)[i], strchr))
			return (&(input->env)[i]);
		i++;
	}
	return (NULL);
}
