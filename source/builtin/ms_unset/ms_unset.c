/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:49:59 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/07 19:53:10 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	update_env_and_export(char *var, t_input *input);
static void	free_env(t_input *input);
static int	print_error(char *var, int nb_error);

int	ms_unset(const char *var, t_input *input)
{
	char	*copy_var;

	if (!var || !*var)
		return (0);
	copy_var = ft_strdup(var);
	if (!copy_var)
		return (print_error(copy_var, 12));
	if (!get_export(copy_var, input))
		return (print_error(copy_var, -1));
	if (update_env_and_export(copy_var, input))
		return (print_error(copy_var, 12));
	free(copy_var);
	return (0);
}

static int	update_env_and_export(char *var, t_input *input)
{
	char	**new_env;

	ls_clear_one_export(&(input->export), var);
	if (ms_get_env(var, input))
	{
		new_env = del_one_env(var, input);
		if (!new_env)
			return (1);
		free_env(input);
		input->env = new_env;
	}
	return (0);
}

static void	free_env(t_input *input)
{
	int	i;

	i = 0;
	if (input->env)
	{
		while ((input->env)[i])
			free((input->env)[i++]);
		free(input->env);
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