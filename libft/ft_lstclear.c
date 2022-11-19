/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:19:08 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/25 15:17:07 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*copyl;

	copyl = *lst;
	if (lst)
	{
		while (copyl)
		{
			*lst = copyl->next;
			if (del)
				(*del)(copyl->content);
			free(copyl);
			copyl = *lst;
		}
		*lst = NULL;
	}
}
/*
#include <stdio.h>

//----------------------
void	del(void *lst)
{
	lst = NULL;
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

	printf ("\na : %d | b : %d | c : %d | nbr : %d", a, b, c, ft_lstsize(a));
	printf ("\n%d | %d | %d", a->content, b->content, c->content);
	printf ("\n%d | %d | %d\n", a->next, b->next, c->next);

	ft_lstclear(&b, &del);

	printf ("\n%d %d\n", b, c);

	return (0);
}
*/
