/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:09:20 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/12 16:26:03 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	free_function_all(char **stock);

int	update_path(const char *path, char **path_update, t_input *input)
{
	char	pwd[4096];
	char	*save_for_free;
	char	*stock;

	(void) input;
	getcwd(pwd, 4096);
	save_for_free = *path_update;
	stock = ft_strjoin("/", path);
	if (!stock)
		return (1);
	*path_update = ft_strjoin(pwd, stock);
	if (!*path_update)
		return (free_function_all(&stock));
	*path_update = remove_point(*path_update);
	free(stock);
	free(save_for_free);
	return (0);
}

static int	free_function_all(char **stock)
{
	free(*stock);
	return (1);
}
