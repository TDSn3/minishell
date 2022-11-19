/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:15:44 by tda-silv          #+#    #+#             */
/*   Updated: 2021/12/11 09:59:24 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

//----------//

void	ft_comp(unsigned int i, char *s)
{
	printf("%c %d %s\n", s[i - i], i - i, s);
	if (s[i - i] >= 'A' && s[i - i] <= 'Z')
		s[i - i] += 32;
}

//----------//

int	main(void)
{
	char	s[] = "TesT012";
//	void	(*f)(unsigned int, char);
	void	(*f)();

	f = ft_comp;
	ft_striteri(s, f);
	printf("\n%s\n\n", s);
	return (0);
}
*/
