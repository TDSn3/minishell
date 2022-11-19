/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:59:36 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/25 15:19:20 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*nextl;
	size_t	i;

	i = 0;
	nextl = lst;
	if (lst)
	{
		while (nextl)
		{
			nextl = nextl->next;
			i++;
		}
	}
	return (i);
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

	printf ("\n%d | %d | %d\n", a->next, b->next, c->next);

	printf("\n%d\n", ft_lstsize(a));
	return (0);
}
*/
