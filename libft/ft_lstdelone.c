/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:19:34 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/17 17:47:09 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del)
		(*del)(lst->content);
	if (lst)
		free(lst);
}
/*
#include <stdio.h>

//----------------------
void	del(void *lst)
{
//	lst->content = NULL;
//	lst->next = NULL;
}
//----------------------

int	main()
{
	t_list *a;
	t_list *b;
	t_list *c;

	a = ft_lstnew((int *)1);
	b = ft_lstnew((int *)2);
	c = ft_lstnew((int *)3);

	ft_lstadd_back(&a, b);
	ft_lstadd_back(&a, c);

	printf ("\na : %d | b : %d | c : %d", a, b, c);
	printf ("\n%d | %d | %d", a->content, b->content, c->content);
	printf ("\n%d | %d | %d\n", a->next, b->next, c->next);

	ft_lstdelone(b, &del);

	printf ("\na : %d | b : %d | c : %d", a, b, c);
	printf ("\n%d | %d | %d", a->content, b->content, c->content);
	printf ("\n%d | %d | %d\n", a->next, b->next, c->next);
	
	return (0);
}
*/
