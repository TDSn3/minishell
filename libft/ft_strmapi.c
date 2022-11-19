/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:18:30 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/17 17:47:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s_after;
	size_t	i;

	s_after = malloc(ft_strlen(s) + 1);
	if (!s_after)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		s_after[i] = (*f)(i, s[i]);
		i++;
	}
	s_after[i] = 0;
	return (s_after);
}
/*
#include <stdio.h>

// FONCTION FT_ADD A DEPLACER //

char	ft_add(unsigned int nbr, char c)
{
	c++;
	return (c);
}

//----------------------------//

int	main(void)
{
	char	c;
	c = ft_add(1, 'a');
	printf("\n%c\n", c);

	char	s[] = "0abcdefghijkklmnopqrstuvwxy0";
	char	*c3;

	char	(*f)(unsigned int, char);
	f = ft_add;

	c3 = ft_strmapi(s, f);
	printf("\n%s\n\n", c3);
	free(c3);
	return (0);
}
*/
