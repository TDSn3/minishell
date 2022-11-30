/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_streplace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:24:26 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/30 00:24:41 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

char	*ft_streplace(char *oldstr, char *newstr)
{
	if (oldstr)
		free(oldstr);
	oldstr = NULL;
	return (newstr);
}
