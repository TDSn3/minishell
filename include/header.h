/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:29:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/25 16:00:50 by tda-silv         ###   ########.fr       */
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

int		copy_env(char **strd);
void	init_input(t_input *input, char *line);
void	free_input(t_input *input);
void	lexer(t_input *input, char *line);
char	*ms_get_env(char *strchr);
char	**ms_get_env_start(char *strchr);
char	*ms_show_env(void);


/* ************************************************************************** */
/*																			  */
/*   ../source/t_map/                            							  */
/*																			  */
/* ************************************************************************** */

void	map_add(t_map **lst, t_map *new);
t_map	*map_last(t_map *lst);
t_map	*map_new(char *content, t_type type);
void	map_delone(t_map *lst, void (*del)(void*));
void	map_clear(t_map **lst, void (*del)(void *));

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

/*   CD   ******************************************************************* */
int		ms_cd(const char *path);
int		update_env(const char *str);
int		update_env_home(const char *str);
int		update_path(const char *path, char **path_update);
void	get_oldpwd(char *str);
char	*remove_point(char *str);
int		remove_last(char **copy);

/*   EXPORT   *************************************************************** */
int		ms_export(char *var);
int		copy_env_in_export(void);
int		wrong_name_var(char *var);
int		get_export(char *strchr);
int		show_export(void);

/*   UNSET   **************************************************************** */
int		ms_unset(const char *var);
void	ls_clear_one_export(t_ls **lst, char *content);
char	**del_one_env(char *var);

#endif
