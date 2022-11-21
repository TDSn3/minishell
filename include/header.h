/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:29:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/21 23:09:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/resource.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <errno.h>
# include <string.h>

# include <stdbool.h>

# include <libft.h>
# include "./struct.h"

/* ************************************************************************** */
/*																			  */
/*   ../source/                    											  */
/*																			  */
/* ************************************************************************** */

void	init_input(t_input *input, char *line);
void	free_input(t_input *input);
void	lexer(t_input *input, char *line);

/* ************************************************************************** */
/*																			  */
/*   ../source/t_map/                            							  */
/*																			  */
/* ************************************************************************** */

void	map_add(t_map **lst, t_map *new);
t_map	*map_last(t_map *lst);
t_map	*map_new(char *content, t_type type);
void    map_delone(t_map *lst, void (*del)(void*));
void	map_clear(t_map **lst, void (*del)(void *));
char	*ft_get_env(char *strchr);
char	**ft_get_env_start(char *strchr);

/* ************************************************************************** */
/*																			  */
/*   ../source/t_gd/                             							  */
/*																			  */
/* ************************************************************************** */

void	init_t_g_sig(void);

/* ************************************************************************** */
/*																			  */
/*   ../source/builtin/                            							  */
/*																			  */
/* ************************************************************************** */

int		ft_cd(const char *path);

#endif
