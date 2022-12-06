/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:29:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/06 13:34:09 by tda-silv         ###   ########.fr       */
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

int		copy_env(char **strd);
void	init_input(t_input *input, char *line);
void	free_input(t_input *input);
char	*ms_get_env(char *strchr);
char	**ms_get_env_start(char *strchr);
int	    free_all(void);


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

void	init_t_gd(void);

/* ************************************************************************** */
/*																			  */
/*   ../source/builtin/                            							  */
/*																			  */
/* ************************************************************************** */

int		builtin_chr(char **argv);
int		ms_env(void);
int		ms_pwd(void);

/*   CD   ******************************************************************* */
int		ms_cd(const char *path);
int		update_env(const char *str);
int		update_env_home(const char *str);
int		update_path(const char *path, char **path_update);
int		get_oldpwd(char *str);
char	*remove_point(char *str);
int		remove_last(char **copy);
int		one_point(char **copy, int i);
int		two_point(char **copy, int i);

/*   EXPORT   *************************************************************** */
int		ms_export(char *var);
int		copy_env_in_export(void);
int		wrong_name_var(char *var);
char	*get_export(char *strchr);
int		show_export(void);

/*   UNSET   **************************************************************** */
int		ms_unset(const char *var);
void	ls_clear_one_export(t_ls **lst, char *content);
char	**del_one_env(char *var);

/* ************************************************************************** */
/*																			  */
/*   ../source/execute/                             						  */
/*																			  */
/* ************************************************************************** */

char	*cmd_path_chr(char *cmd);
void	execute_cmd(char *cmd, char **argv);

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
