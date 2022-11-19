/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:11:42 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/31 13:41:41 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_setsize_l(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] && set[j])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static size_t	ft_setsize_r(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	if (i > 0)
		i--;
	j = 0;
	while (s1[i] && set[j])
	{
		if (s1[i] == set[j])
		{
			if (i == 0)
				break ;
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*copy;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if (ft_setsize_r(s1, set) < ft_setsize_l(s1, set))
		return (ft_strdup(""));
	i = ft_setsize_r(s1 + ft_setsize_l(s1, set), set);
	if (ft_setsize_l(s1, set) == 0 && ft_setsize_r(s1, set) == 0 && !*s1)
		i += 1;
	else
		i += 2;
	copy = malloc(i);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1 + ft_setsize_l(s1, set), i);
	return (copy);
}
/*
//#include <stdio.h>

int	main(void)
{
	char	s1[] = "---";
	char	*s11 = ft_strtrim(s1, "-");

	printf("\n%s\n\n", s11);
	free(s11);
	return (0);
}
*/
