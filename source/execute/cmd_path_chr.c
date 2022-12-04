/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:01:00 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/03 22:01:44 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	check_path(char ***all_path, char *cmd);
static char	*test_path(char ***all_path);

/* ************************************************************************** */
/*																			  */
/*   Cherche l'executable de la commande cmd dans la variable PATH. Return	  */
/*   le path de l'executable, si il est trouvé, sinon, return NULL.			  */
/*																			  */
/* ************************************************************************** */
char	*cmd_path_chr(char *cmd)
{
	char	**all_path;
	char	*copy_for_return;
	int		i;

	i = 0;
	all_path = ft_split(ms_get_env("PATH") + 1, ':');
	if (!all_path)
		return (NULL);
	if (check_path(&all_path, cmd))
		return (NULL);
	copy_for_return = test_path(&all_path);
	if (copy_for_return)
		return (copy_for_return);
	while (all_path[i])
		free(all_path[i++]);
	free(all_path);
	return (NULL);
}

/* ************************************************************************** */
/*																			  */
/*   Concat cmd dans chaque ligne d'all_path avec ft_strjoin().		 		  */
/*																			  */
/* ************************************************************************** */
static int	check_path(char ***all_path, char *cmd)
{
	int		i;
	char	*save_for_free;

	i = 0;
	while ((*all_path)[i])
	{
		save_for_free = (*all_path)[i];
		(*all_path)[i] = ft_strjoin ((*all_path)[i], "/");
		if (!(*all_path)[i])
			return (1);
		free(save_for_free);
		save_for_free = (*all_path)[i];
		(*all_path)[i] = ft_strjoin ((*all_path)[i], cmd);
		if (!(*all_path)[i])
			return (1);
		free(save_for_free);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*																			  */
/*   Verifie l'existance de l'executable et les droits d'execution pour		  */
/*   chaque PATH.															  */
/*   Si un executable fonctionnel est trouvé, return sont path, sinon,	 	  */
/*   return NULL.															  */
/*																			  */
/* ************************************************************************** */
static char	*test_path(char ***all_path)
{
	int		i;
	char	*copy_for_return;

	i = 0;
	while ((*all_path)[i])
	{
		if (access((*all_path)[i], F_OK | X_OK) > -1)
		{
			copy_for_return = ft_strdup((*all_path)[i]);
			if (!copy_for_return)
				return (NULL);
			i = 0;
			while ((*all_path)[i])
				free((*all_path)[i++]);
			free((*all_path));
			return (copy_for_return);
		}
		i++;
	}
	return (NULL);
}
