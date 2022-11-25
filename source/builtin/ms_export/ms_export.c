/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:58:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/25 10:37:20 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	free_env(void);
static int	check_dollar(char **var);
static int	print_error(char *var);

int	ms_export(char *var)
{
	char	*copy_var;
	char	**new_env;

	if (!var || !*var)
		return (show_export());
	new_env = NULL;
	copy_var = ft_strdup(var);
	if (!copy_var)
		return (print_error(copy_var));
	if (check_dollar(&copy_var) || wrong_name_var(copy_var))
		return (print_error(copy_var));
	if (my_strchr_pos(copy_var, '=') > -1)
	{
		new_env = my_strdjoin(g_d.env, copy_var);
		if (!new_env)
			return (print_error(copy_var));
		free_env();
		g_d.env = new_env;
	}
	ls_add_back(&(g_d.export), ls_new(copy_var));
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

static int	print_error(char *var)
{
	perror("export");
	if (var)
		free(var);
	return (1);
}

/*	Tests pour le main
	ms_show_env();
	printf("\n\n");

	ms_export("");
	ms_export("TEST=test");
	ms_export("TEST2=");
	ms_export("TEST3");
	ms_export("TEST4==");
	ms_export("=");
	ms_export("=test");
	ms_export("?=test");
	ms_export("t$est5=error");
	printf("--\n");
	ms_export("$test6=test");
	ms_export("$==$");
	printf("--\n");
	ms_export("test7=test");
	ms_export("$test7=OKOK");
	ms_export("TEST?8=error");
	ms_show_env();
	printf("\n\n");

	ms_export("");
*/
