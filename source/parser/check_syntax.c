/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:38:40 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/12 11:17:51 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	lexer_str_error(t_input *input, char *message, char *content);

int	check_syntax(t_input *input)
{
	t_map	*tmp;

	tmp = input->lexer;
	while (tmp)
	{
		if (is_break(tmp->type))
		{
			if (tmp->next)
			{
				if (tmp->next->type != WORD)
					return (lexer_str_error(input,
							"error : unexpeted token : ` ",
							tmp->next->content));
			}
			else
				return (lexer_str_error(input,
						"error : unexpeted token : << newline >>", NULL));
		}
		tmp = tmp->next;
	}
	return (1);
}

static int	lexer_str_error(t_input *input, char *message, char *content)
{
	printf("%s", message);
	if (content)
		printf("%s", content);
	printf("\n");
	(void) input;
	return (0);
}
