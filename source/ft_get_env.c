/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:42:02 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/21 23:54:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	str_chr_start_str(char *str, char *strchr);

/* ************************************************************************** */
/*																			  */
/*   Cherche strchr au début de chaque env*. Si strchr n'est trouvée dans	  */
/*   aucune str d'env*, retourne NULL, sinon, retourne la ligne débutant	  */
/*   par strchr après celui-ci.												  */
/*																			  */
/* ************************************************************************** */
char	*ft_get_env(char *strchr)
{
	int	i;

	i = 0;
	while (g_d.env[i])
	{
		if (str_chr_start_str(g_d.env[i], strchr))
			return (g_d.env[i] + ft_strlen(strchr));
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
