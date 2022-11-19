/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:19:00 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/24 20:53:45 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DL_H
# define T_DL_H

typedef struct s_double_list
{
	int						content;
	struct s_double_list	*prev;
	struct s_double_list	*next;
	t_li					*prev_li;
	t_li					*next_li;
}	t_dl;

int		dl_add_back(t_dl **lst, t_dl *new);
void	dl_clear_one(t_dl **lst, int content);
void	dl_clear(t_dl **lst);
t_dl	*dl_last(t_dl *lst);
t_dl	*dl_new(int content);
int		dl_size(t_dl *lst);
t_li	*dl_find_content(t_dl *lst, int content);

#endif