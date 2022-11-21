/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:11:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/21 12:10:48 by tda-silv         ###   ########.fr       */
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

typedef struct s_global_signal {
	int	signal;
}	t_g_sig;

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

#endif
