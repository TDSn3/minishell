/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:46:28 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/06 23:06:41 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	ms_echo(char **argv)
{
	int	i;

	i = 1;
	if (argv[1])
	{
		if (!my_strcmp(argv[1], "-n"))
		{
			if (argv[2])
			{
				while (argv[++i])
				{
					printf("%s", argv[i]);
					if (argv[i + 1])
						printf(" ");
				}
			}
		}
		else
		{
			while (argv[i])
			{
				printf("%s", argv[i++]);
				if (argv[i])
					printf(" ");
			}
			printf("\n");
		}
	}
	else
		printf("\n");
	return (0);
}
