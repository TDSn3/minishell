/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:27:43 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/17 04:34:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	free_function_all(char ***copy);

int	copy_env(char **strd, t_input *input)
{
	int		i;
	int		x;
	int		y;
	char	**copy;

	if (!strd || !*strd || !**strd)
		return (0);
	x = my_strdlen(strd);
	copy = ft_calloc(x + 1, sizeof(char *));
	if (!copy)
		return (1);
	i = 0;
	while (i < x)
	{
		y = ft_strlen(strd[i]);
		copy[i] = ft_calloc(y + 1, sizeof(char));
		if (!copy[i])
			return (free_function_all(&copy));
		ft_strlcpy(copy[i], strd[i], y + 1);
		i++;
	}
	copy[x] = NULL;
	input->env = copy;
	return (0);
}

static int	free_function_all(char ***copy)
{
	int	i;

	i = 0;
	if (copy && *copy && **copy)
		while ((*copy)[i])
			free((*copy)[i++]);
	if (copy && *copy)
		free(*copy);
	return (1);
}
