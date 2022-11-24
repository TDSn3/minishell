/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:42:02 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/24 20:15:07 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	str_chr_start_str(char *str, char *strchr);

/* ************************************************************************** */
/*																			  */
/*   Cherche strchr dans la struct "t_ls g_d.export".						  */
/*																			  */
/* ************************************************************************** */
int	get_export(char *strchr)
{
	t_ls	*copy;

	copy = g_d.export;
	while (copy)
	{
		if (str_chr_start_str(copy->content_one, strchr))
			return (1);
		copy = copy->next;
	}
	return (0);
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
