/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:04:28 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/21 11:44:08 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copyl;
	t_list	*copyn;

	copyn = NULL;
	if (!lst || !f)
		return (NULL);
	copyl = ft_lstnew(f(lst->content));
	if (!copyl)
	{
		ft_lstclear(&copyl, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&copyl, copyn = ft_lstnew(f(lst->content)));
		if (!copyn)
		{
			ft_lstclear(&copyl, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (copyl);
}
/*
//
#include <stdio.h>

void	del(void *lcontent)
{
	*(int *)lcontent = 0;
}

void	lst_printf(void *lcontent)
{
	printf("\n%d + 5 = ", *(int *)lcontent);
	*(int *)lcontent += 5;
	printf("%d\n", *(int *)lcontent);
}

void	*lst_printf_two(void *lcontent)
{
	printf("\n%d + 10 = ", *(int *)lcontent);
	*(int *)lcontent += 10;
	printf("%d\n", *(int *)lcontent);
}
//

int	main()
{
	t_list *a;
	t_list *b;
	t_list *c;
	t_list *copy;

	int	aa = 5;
	int	bb = 10;
	int	cc = 15;

	a = ft_lstnew(&aa);
	b = ft_lstnew(&bb);
	c = ft_lstnew(&cc);

	ft_lstadd_back(&a, b);
	ft_lstadd_back(&a, c);

//	ft_lstiter(a, lst_printf);

	copy = ft_lstmap(a, lst_printf_two, del);
	ft_lstiter(copy, lst_printf);
	write(1, "\n", 1);

	return (0);
}
*/
