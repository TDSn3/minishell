/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:58:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/24 20:16:13 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	free_env(void);
static int	check_dollar(char **var);
static int	print_error(void);

int	ms_export(char *var)
{
	char	*copy_var;
	char	**new_env;

	if (!var || !*var)
		return (show_export());
	copy_var = ft_strdup(var);
	if (!copy_var)
		return (print_error());
	if (check_dollar(&copy_var) || wrong_name_var(copy_var))
		return (print_error());
	new_env = my_strdjoin(g_d.env, copy_var);
	if (!new_env)
		return (print_error());
	ls_add_back(&(g_d.export), ls_new(copy_var));
	free_env();
	g_d.env = new_env;
	return (0);
}

static int	check_dollar(char **var)
{
	char	*save_for_free;
	int		pos;

	if ((*var)[0] == '$' && (*var)[1])
	{
		save_for_free = *var;
		*var = ft_strdup((*var) + 1);
		free(save_for_free);
		pos = my_strchr_pos(*var, '=');
		if (pos > -1)
		{
			(*var)[pos] = 0;
			if (get_export(*var))
			{
				(*var)[pos] = '=';
				return (0);
			}
			(*var)[pos] = '=';
		}
		if (get_export(*var))
			return (0);
		return (1);
	}
	return (0);
}

static void	free_env(void)
{
	int	i;

	i = 0;
	if (g_d.env)
	{
		while (g_d.env[i])
			free(g_d.env[i++]);
		free(g_d.env);
	}
}

static int	print_error(void)
{
	perror("export");
	return (1);
}
