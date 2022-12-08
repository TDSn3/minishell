/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:29:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/08 09:07:28 by tda-silv         ###   ########.fr       */
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
# include <termios.h>

# include <stdbool.h>

# include <libft.h>
# include "./struct.h"

/* ************************************************************************** */
/*																			  */
/*   ../source/                    											  */
/*																			  */
/* ************************************************************************** */

void	free_input(t_input *input);
char	*ms_get_env(char *strchr, t_input *input);
char	**ms_get_env_start(char *strchr, t_input *input);
int		free_all(t_input *input);
int		str_chr_start_str(char *str, char *strchr);

/* ************************************************************************** */
/*																			  */
/*   ../source/start_main/            	                 					  */
/*																			  */
/* ************************************************************************** */

int		copy_env(char **strd, t_input *input);
int		copy_env_in_export(t_input *input);
void	init_input(t_input *input, char *line);
int		shlvl(t_input *input);
int		ms_path_var(char **argv, t_input *input);

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
/*   ../source/builtin/                            							  */
/*																			  */
/* ************************************************************************** */

int		builtin_chr(char **argv, t_input *input);
int		ms_env(t_input *input);
int		ms_pwd(t_input *input);
int		ms_echo(char **str);
void	ms_exit(t_input *input);

/*   CD   ******************************************************************* */
int		ms_cd(const char *path, t_input *input);
int		update_env(const char *str, t_input *input);
int		update_env_home(const char *str, t_input *input);
int		update_path(const char *path, char **path_update, t_input *input);
int		get_oldpwd(char *str, t_input *input);
char	*remove_point(char *str);
int		remove_last(char **copy);
int		one_point(char **copy, int i);
int		two_point(char **copy, int i);

/*   EXPORT   *************************************************************** */
int		ms_export(char *var, t_input *input);
int		wrong_name_var(char *var);
char	*get_export(char *strchr, t_input *input);
int		show_export(t_input *input);

/*   UNSET   **************************************************************** */
int		ms_unset(const char *var, t_input *input);
void	ls_clear_one_export(t_ls **lst, char *content);
char	**del_one_env(char *var, t_input *input);

/* ************************************************************************** */
/*																			  */
/*   ../source/execute/                             						  */
/*																			  */
/* ************************************************************************** */

char	*cmd_path_chr(char *cmd, t_input *input);
void	execute_cmd(char *cmd, char **argv, t_input *input);

/* ************************************************************************** */
/*																			  */
/*   ../source/lexer/            	                 						  */
/*																			  */
/* ************************************************************************** */

void	lexer(t_input *input, char *line);
t_type	switch_type(char c);
int		is_break(t_type type);
void	lexer_char_error(t_input *input, char *message, char content);

/* ************************************************************************** */
/*																			  */
/*   ../source/parser/            	                 						  */
/*																			  */
/* ************************************************************************** */

void	parser(t_input *input);
char	*ft_streplace(char *oldstr, char *newstr);
char	**ft_strdjoin(char **strd, char *s);
size_t	ft_strdlen(char **strd);
void	ft_strdfree(char **strd);
void	check_syntax(t_input *input);
void	check_expand(t_input *input);
char	*ft_strjoin_free(char *s1, char const *s2);

#endif
