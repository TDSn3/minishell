/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:55:54 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/29 20:56:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_type	switch_type(char c)
{
	if (c == '\"')
		return (DQUOTE);
	if (c == '\'')
		return (SQUOTE);
	if (c == '$')
		return (DOLLAR);
	if (c == ' ')
		return (ESPACE);
	if (c == '|')
		return (PIPE);
	if (c == '<')
		return (GREDIR);
	if (c == '>')
		return (DREDIR);
	return (WORD);
}
