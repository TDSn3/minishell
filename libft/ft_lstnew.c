/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/16 17:26:42 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ln;

	ln = malloc(sizeof(t_list));
	if (!ln)
		return (NULL);
	ln->content = content;
	ln->next = NULL;
	return (ln);
}
/*
#include <stdio.h>

int	main()
{
	t_list *socrate;

	socrate = ft_lstnew((int *)5);
	printf("\n%d\n", socrate->content);
	free(socrate);
	return (0);
}
*/
