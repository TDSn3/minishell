/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:19:00 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/24 14:18:18 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LS_H
# define T_LS_H

typedef struct s_list_str
{
	char				*content_one;
	struct s_list_str	*prev;
	struct s_list_str	*next;
}	t_ls;

int		ls_add_back(t_ls **lst, t_ls *new);
void	ls_clear_one(t_ls **lst, char *content);
void	ls_clear(t_ls **lst);
t_ls	*ls_last(t_ls *lst);
t_ls	*ls_new(char *content_one);
int		ls_size(t_ls *lst);
char	*ls_find_content(t_ls *lst, char *content);

#endif