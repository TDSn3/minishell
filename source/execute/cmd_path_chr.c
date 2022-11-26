/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:01:00 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/26 21:29:13 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*																			  */
/*   Cherche l'executable de la commande cmd dans la variable PATH. Return	  */
/*   le path de l'executable, si il est trouvé, sinon, return NULL.			  */
/*																			  */
/* ************************************************************************** */
char	*cmd_path_chr(char *cmd)
{
	char	**all_path;
	char	*save_for_free;
	char	*copy_for_return;
	int		i;

	i = 0;
	all_path = ft_split(ms_get_env("PATH") + 1, ':');
	while (all_path[i])
	{
		save_for_free = all_path[i];
		all_path[i] = ft_strjoin (all_path[i], "/");
		if (!all_path[i])
			return (NULL);
		free(save_for_free);
		save_for_free = all_path[i];
		all_path[i] = ft_strjoin (all_path[i], cmd);
		if (!all_path[i])
			return (NULL);
		free(save_for_free);
		i++;
	}
	i = 0;
	while (all_path[i])
	{
		if (access(all_path[i], F_OK | X_OK) > -1)
		{
			copy_for_return = ft_strdup(all_path[i]);
			if (!copy_for_return)
				return (NULL);
			i = 0;
			while (all_path[i])
				free(all_path[i++]);
			free(all_path);
			return (copy_for_return);
		}
		i++;
	}
	while (all_path[i])
		free(all_path[i++]);
	free(all_path);
	return (NULL);
}
