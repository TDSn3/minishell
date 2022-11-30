/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:24:58 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/30 19:27:21 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static size_t	ft_strlen2(const char *s);

char	*ft_strjoin_free(char *s1, char const *s2)
{
	size_t	count;
	size_t	copy;
	size_t	len;
	char	*all;

	count = 0;
	copy = 0;
	len = ft_strlen2(s1);
	if (!s1 && !s2)
		return (NULL);
	all = (char *) ft_calloc(len + ft_strlen2(s2) + 1, sizeof(char));
	if (!all)
		return (NULL);
	while (count < len)
		all[copy++] = s1[count++];
	count = 0;
	while (count < ft_strlen2(s2))
		all[copy++] = s2[count++];
	all[copy] = '\0';
	if (len > 0)
		free(s1);
	return (all);
}

static size_t	ft_strlen2(const char *s)
{
	size_t	count;

	count = 0;
	if (!s || s[count] == '\0')
		return (0);
	while (s[count])
		count++;
	return (count);
}
