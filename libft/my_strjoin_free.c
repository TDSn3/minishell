/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:04:52 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/24 21:04:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*one_is_null(char **s1, char **s2);

char	*my_strjoin_free(char **s1, char **s2)
{
	char	*s1s2;

	s1s2 = NULL;
	if (*s1 && *s2)
	{
		s1s2 = malloc(ft_strlen(*s1) + ft_strlen(*s2) + 1);
		if (!s1s2)
			return (NULL);
		ft_strlcpy(s1s2, *s1, ft_strlen(*s1) + 1);
		ft_strlcpy(s1s2 + ft_strlen(*s1), *s2, ft_strlen(*s2) + 1);
		free(*s1);
		free(*s2);
		return (s1s2);
	}
	if ((*s1 && !*s2) || (!*s1 && *s2))
		s1s2 = one_is_null(s1, s2);
	if (s1s2)
		return (s1s2);
	return (NULL);
}

static char	*one_is_null(char **s1, char **s2)
{
	char	*s1s2;

	if (*s1 && !*s2)
	{
		s1s2 = malloc(ft_strlen(*s1) + 1);
		if (!s1s2)
			return (NULL);
		ft_strlcpy(s1s2, *s1, ft_strlen(*s1) + 1);
		free(*s1);
		return (s1s2);
	}
	if (!*s1 && *s2)
	{
		s1s2 = malloc(ft_strlen(*s2) + 1);
		if (!s1s2)
			return (NULL);
		ft_strlcpy(s1s2, *s2, ft_strlen(*s2) + 1);
		free(*s2);
		return (s1s2);
	}
	return (NULL);
}
