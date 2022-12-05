/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:41:13 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/05 18:59:10 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1s2;
	char	*str;

	if (s1 && !s2)
	{
		str = ft_strdup(s1);
		if (!str)
			return (NULL);
		return (str);
	}
	if (!s1 && s2)
	{
		str = ft_strdup(s2);
		if (!str)
			return (NULL);
		return (str);
	}
	if (!s1 && !s2)
		return (NULL);
	s1s2 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1s2)
		return (NULL);
	ft_strlcpy(s1s2, s1, ft_strlen(s1) + 1);
	ft_strlcpy(s1s2 + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (s1s2);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s1[] = "Super";
	char	s2[] = "Test";
	char	*s1s2 = ft_strjoin(s1, s2);

	printf("\n%s\n%ld\n", s1s2, ft_strlen(s1s2));
	free(s1s2);
	return (0);
}
*/
