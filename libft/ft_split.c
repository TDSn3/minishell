/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:44:13 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/08 12:37:38 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbc(char const *s, char c)
{
	unsigned int	i;
	size_t			j;

	i = 0;
	j = 1;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
			continue ;
		}
		i++;
	}
	return (j);
}

static size_t	ft_skip_o(char const *s, char c, size_t *pos)
{
	size_t	i;

	i = 0;
	if (*(s + *pos) && *(s + *pos) == c)
		while (*(s + *pos) && *(s + *pos) == c)
			*pos += 1;
	while (*(s + *pos) && *(s + *pos) != c)
	{
		*pos += 1;
		i++;
	}
	return (i);
}

static size_t	ft_skip_c(char const *s, char c, size_t *pos)
{
	size_t	i;

	i = 0;
	while (*(s + *pos) && *(s + *pos) == c)
		*pos += 1;
	while ((s + *pos)[i] && (s + *pos)[i] != c)
		i++;
	return (i);
}

static void	ft_split_pii(char const *s, char c, size_t x, char **ssplit)
{
	size_t	i;

	i = 0;
	while (i < ft_nbc(s, c) - 1)
	{
		ssplit[i] = malloc(ft_skip_o(s, c, &x) + 1);
		if (!ssplit[i])
		{
			while (i-- > 0)
				free(ssplit[i]);
			free(ssplit);
		}
		i++;
	}
	ssplit[ft_nbc(s, c) - 1] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**ssplit;
	size_t	x;
	size_t	y;
	size_t	i;

	x = 0;
	y = 0;
	i = 0;
	if (!s || !*s)
		return (NULL);
	ssplit = (char **) malloc(sizeof (char *) * ft_nbc(s, c));
	if (!ssplit)
		return (NULL);
	ft_split_pii(s, c, x, ssplit);
	while (i < ft_nbc(s, c) - 1)
	{
		if (*(s + y))
		{
			x = ft_skip_c(s, c, &y) + 1;
			ft_strlcpy(ssplit[i], s + y, x);
			ft_skip_o(s, c, &y);
		}
		i++;
	}
	return (ssplit);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
//	char	s[] = "";
	char	**ssplit = NULL;

	(void)argc;
	ssplit = ft_split(argv[1], argv[2][0]);
	printf("\n--------------------\n");
	printf("\ns:%s\nc:%c\n", argv[1], argv[2][0]);
	printf("\n[0]%s\n", ssplit[0]);
	
	int i = 1;
	while (ssplit[i])
	{
		printf("[%d]%s\n", i, ssplit[i]);
		i++;
	}

////FREE////

	printf("\n--------------------\n");
	while (i >= 0)
	{
		free(ssplit[i]);
		printf("\n[%d] is free", i);
		i--;
	}
	printf("\n");
	free(ssplit);
	return (0);
}
*/
