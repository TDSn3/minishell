/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:11:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/24 14:00:07 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_type{
	WORD,
	SQUOTE,
	DQUOTE,
	CMD,
	DELIM
}	t_type;

typedef struct s_map {
	int				key;
	char			*content;
	t_type			type;
	struct s_map	*next;
}	t_map;

typedef struct s_input {
	char	**env;
	char	*raw;
	char	*line;
	t_map	*lexer;
}	t_input;

typedef struct s_global_data {
	int		signal;
	char	**env;
	t_ls	*export;
}	t_gd;

t_gd	g_d;

#endif
