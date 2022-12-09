/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:42:02 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/08 23:33:20 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*																			  */
/*   Cherche strchr au début de chaque env. Si strchr n'est trouvée dans	  */
/*   aucune str d'env, retourne NULL, sinon, retourne la ligne débutant		  */
/*   par strchr après celui-ci.												  */
/*																			  */
/* ************************************************************************** */
char	*ms_get_env(char *strchr, t_input *input)
{
	int		i;
	char	*stock;

	i = 0;
	if (!input->env)
		return (NULL);
	while ((input->env)[i])
	{
		if (str_chr_start_str((input->env)[i], strchr))
		{
			stock = (input->env)[i] + ft_strlen(strchr);
			if (stock && stock[0] && stock[0] == '=')
				return (stock + 1);
			else
				return (stock);
		}
		i++;
	}
	return (NULL);
}
