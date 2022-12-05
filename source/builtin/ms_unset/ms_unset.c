/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:49:59 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/05 20:25:09 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	wrong_name_var_export(char *var);
static int	update_env_and_export(char *var);
static void	free_env(void);
static int	print_error(char *var, int nb_error);

int	ms_unset(const char *var)
{
	char	*copy_var;

	if (!var || !*var)
		return (0);
	copy_var = ft_strdup(var);
	if (!copy_var)
		return (print_error(copy_var, 12));
	if (wrong_name_var_export(copy_var))
		return (print_error(copy_var, -1));
	if (update_env_and_export(copy_var))
		return (print_error(copy_var, 12));
	printf("-->%s\n", var);
	free(copy_var);
	return (0);
}

static int	wrong_name_var_export(char *var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		if (!ft_isalnum(var[i]) && var[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

static int	update_env_and_export(char *var)
{
	char	**new_env;

	ls_clear_one_export(&g_d.export, var);
	new_env = del_one_env(var);
	if (!new_env)
		return (1);
	free_env();
	printf("ok\n");
	g_d.env = new_env;
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
		printf("unset: `%s': not a valid identifier\n", var);
	else
	{
		errno = nb_error;
		perror("unset");
	}
	if (var)
		free(var);
	return (1);
}

/*	Tests pour le main
	printf("\033[36;01m$> \033[00mexport\n");
	ms_export("");
	printf("----------\n\033[36m");
	ms_show_env();

	printf("\033[00m\n\n");

	printf("\033[36;01m$> \033[00mexport TEST=test1\n");
	ms_export("TEST=test1");

	printf("\n\n");

	printf("\033[36;01m$> \033[00mexport\n");
	ms_export("");
	printf("----------\n\033[36m");
	ms_show_env();

	printf("\033[00m\n\n");
	
	printf("\033[36;01m$> \033[00munset TEST\n");
	ms_unset("TEST");
	ms_unset("USER");
	
	printf("\n\n");
	
	printf("\033[36;01m$> \033[00mexport\n");
	ms_export("");
	printf("----------\n\033[36m");
	ms_show_env();
	printf("\033[00m\n\n");
*/