/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_char_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:18:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/29 21:20:00 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	lexer_char_error(t_input *input, char *message, char content)
{
	printf("%s", message);
	if (content)
		printf("%c", content);
	printf("\n");
	free_input(input);
	exit(0);
}
