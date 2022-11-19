/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_li.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:19:00 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/10 19:44:27 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LI_H
# define T_LI_H

typedef struct s_list_int
{
	int					content_one;
	int					content_two;
	int					content_three;
	int					content_four;
	int					content_five;
	struct s_list_int	*prev;
	struct s_list_int	*next;
}	t_li;

int		li_add_back(t_li **lst, t_li *new);
void	li_clear_one(t_li **lst, int content);
void	li_clear(t_li **lst);
t_li	*li_last(t_li *lst);
t_li	*li_new(int content_one, int content_two);
int		li_size(t_li *lst);
int		li_find_content(t_li *lst, int pid);

#endif