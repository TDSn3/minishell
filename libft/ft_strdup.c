/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:31:35 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/16 12:40:52 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;

	copy = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, ft_strlen(s) + 1);
	return (copy);
}
/*
#include <stdio.h>

int	main(void)
{
	char	tab1[] = "";
	char	*copy1;

	copy1 = ft_strdup(tab1);
	printf("\n%s\n\n", copy1);
	return (0);
}
*/
