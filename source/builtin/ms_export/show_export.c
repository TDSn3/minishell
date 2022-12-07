/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:32:24 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/07 15:36:03 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	show_export(t_input *input)
{
	t_ls	*copy;
	char	*after_equal;
	int		pos;

	copy = input->export;
	if (!copy || !(copy->content_one) || !*(copy->content_one))
		return (0);
	while (copy)
	{
		after_equal = ft_strchr(copy->content_one, '=');
		if (after_equal)
			after_equal += 1;
		pos = my_strchr_pos(copy->content_one, '=');
		if (pos > -1)
		{
			copy->content_one[pos] = 0;
			printf("export %s=", copy->content_one);
			copy->content_one[pos] = '=';
			printf("\"%s\"\n", after_equal);
		}
		else
			printf("export %s\n", copy->content_one);
		copy = copy->next;
	}
	return (0);
}
