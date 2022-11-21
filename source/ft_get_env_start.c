/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:42:02 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/21 23:40:30 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	str_chr_start_str(char *str, char *strchr);

/* ************************************************************************** */
/*																			  */
/*   Similaire à ft_get_env, mais renvois un double pointeur de toute 		  */
/*   la ligne.											  					  */
/*																			  */
/* ************************************************************************** */
char	**ft_get_env_start(char *strchr)
{
	int	i;

	i = 0;
	while (g_d.env[i])
	{
		if (str_chr_start_str(g_d.env[i], strchr))
			return (&g_d.env[i]);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*																			  */
/*   Cherche strchr au début de str. Si strchr n'est pas imédiatement		  */
/*   trouvé, retounre 0, sinon, retourn 1.									  */
/*																			  */
/* ************************************************************************** */
static int	str_chr_start_str(char *str, char *strchr)
{
	int	i;

	i = 0;
	if (!str || !strchr)
		return (0);
	while (str[i] && strchr[i])
	{
		if (str[i] == strchr[i])
			i++;
		else
			return (0);
	}
	if (!strchr[i])
		return (1);
	return (0);
}
