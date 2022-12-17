/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_one_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:41:15 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/15 10:34:59 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	cmp_var_and_env(char *env_line, char *var);
static char	**creat_new_env(int i, int i_env, int x, t_input *input);

char	**del_one_env(char *var, t_input *input)
{
	int		i;
	char	**new_env;

	i = 0;
	while ((input->env)[i])
	{
		if (cmp_var_and_env((input->env)[i], var))
		{
			new_env = creat_new_env(i, 0, my_strdlen(input->env), input);
			if (!new_env)
				return (NULL);
			return (new_env);
		}
		i++;
	}
	return (input->env);
}

static char	**creat_new_env(int i, int i_env, int x, t_input *input)
{
	int		y;
	int		pos_del;
	char	**new_env;

	pos_del = i;
	new_env = ft_calloc(x + 1, sizeof(char *));
	if (!new_env)
		return (NULL);
	i = 0;
	while (i < x - 1)
	{
		if (i_env == pos_del)
		{
			i_env++;
			continue ;
		}
		y = ft_strlen((input->env)[i_env]);
		new_env[i] = ft_calloc(y + 1, sizeof(char));
		if (!new_env[i])
			return (NULL);
		ft_strlcpy(new_env[i++], (input->env)[i_env++], y + 1);
	}
	new_env[x] = NULL;
	return (new_env);
}

static int	cmp_var_and_env(char *env_line, char *var)
{
	int	pos;

	pos = my_strchr_pos(env_line, '=');
	if (pos > -1)
		env_line[pos] = 0;
	if (!my_strcmp(env_line, var))
	{
		if (pos > -1)
			env_line[pos] = '=';
		return (1);
	}
	if (pos > -1)
		env_line[pos] = '=';
	return (0);
}
