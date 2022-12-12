/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_char_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:18:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/12 11:15:24 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	lexer_char_error(t_input *input, char *message, char content)
{
	printf("%s", message);
	if (content)
		printf("%c", content);
	printf("\n");
	(void) input;
	return (-1);
}
