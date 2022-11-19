/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:55:57 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/16 17:26:45 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
#include <stdio.h>

int	main()
{
	t_list *a;
	t_list *b;
	t_list *c;

	a = ft_lstnew((int *)1);
	b = ft_lstnew((int *)2);
	c = ft_lstnew((int *)3);

	a->next = b;
	b->next = c;


	printf ("\na : %d | b : %d | c : %d", a, b, c);
	printf ("\n%d | %d | %d", a->content, b->content, c->content);
	printf ("\n%d | %d | %d\n", a->next, b->next, c->next);
  
	ft_lstadd_front(&a, c);
  
	printf ("\n%d | %d | %d", a->content, b->content, c->content);
	printf ("\n%d | %d | %d\n", a->next, b->next, c->next);

	free(a);
	free(b);
//	free(c);

	return (0);
}
*/
