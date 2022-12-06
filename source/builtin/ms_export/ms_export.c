/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:58:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/06 14:44:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	check_doublon(char *var);
static int	update_var(char *var);
static void	free_env(void);
static int	print_error(char *var, int nb_error);

int	ms_export(char *var)
{
	char	*copy_var;
	char	**new_env;

	if (!var || !*var)
		return (show_export());
	new_env = NULL;
	copy_var = ft_strdup(var);
	if (!copy_var)
		return (print_error(copy_var, 12));
	if (wrong_name_var(copy_var))
		return (print_error(copy_var, -1));
	if (check_doublon(var))
	{
		if (update_var(var))
			return (print_error(copy_var, 12));
		return (0);
	}
	if (my_strchr_pos(copy_var, '=') > -1)
	{
		new_env = my_strdjoin(g_d.env, copy_var);
		if (!new_env)
			return (print_error(copy_var, 12));
		free_env();
		g_d.env = new_env;
	}
	ls_add_back(&(g_d.export), ls_new(copy_var));
	return (0);
}

static int	check_doublon(char *var)
{
	int		equal;

	equal = my_strchr_pos(var, '=');
	if (equal > -1)
		var[equal] = 0;
	if (get_export(var))
	{
		if (equal > -1)
			var[equal] = '=';
		return (1);
	}
	if (equal > -1)
		var[equal] = '=';
	return (0);
}

static int	update_var(char *var)
{
	int		equal;

	if (!my_strcmp(var, get_export(var)))
		return (0);
	equal = my_strchr_pos(var, '=');
	if (equal > -1)
		var[equal] = 0;
	if (equal == -1)
		return (0);
	if (ms_unset(var))
	{
		if (equal > -1)
			var[equal] = '=';
		return (1);
	}
	if (equal > -1)
		var[equal] = '=';
	if (ms_export(var))
		return (1);
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

static int	print_error(char *var, int nb_error)
{
	if (nb_error == -1)
		printf("export: `%s': not a valid identifier\n", var);
	else
	{
		errno = nb_error;
		perror("export");
	}
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
	ms_export("9999=error");
	ms_show_env();
	printf("\n\n");

	ms_export("");
*/
