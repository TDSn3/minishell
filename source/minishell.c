/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:33:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/19 18:49:20 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	print_map(t_map *map);

int	main(int argc, char **argv, char **env)
{
	t_input	input;

	(void) argc;
	(void) argv;
	(void) env;
	while (1)
	{
		ft_printf("minishell > ");
		init_input(&input, get_next_line(0), &env);
		lexer(&input, input.raw);
		print_map(input.lexer);
	}
	return (0);
}

static void	print_map(t_map *map)
{
	t_map	*tmp;

	tmp = map;
	while (tmp)
	{
		ft_printf("%d:", tmp->key);
		ft_printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}
