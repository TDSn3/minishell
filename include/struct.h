/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:11:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/07 08:21:54 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_type {
	WORD,
	SQUOTE,
	DQUOTE,
	DOLLAR,
	PIPE,
	ESPACE,
	DREDIR,
	DRREDIR,
	GREDIR,
	GRREDIR
}	t_type;

typedef struct s_map {
	int				key;
	char			*content;
	t_type			type;
	struct s_map	*next;
}	t_map;

typedef struct s_node {
	int		status;
	char	*file;
	char	**args;
}	t_node;

typedef struct s_input {
	char		**env;
//	char		**paths;
	char		*raw;
	char		*line;
	int			fdin;
	int			fdout;
	t_map		*lexer;
	t_map		*parser;
	t_list		*ast;
}	t_input;

typedef struct s_global_data {
	int		signal;
	char	**env;
	t_ls	*export;
}	t_gd;

extern t_gd	g_d;

#endif
