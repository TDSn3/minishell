/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_one_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:41:15 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/25 16:22:09 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	cmp_var_and_env(char *env_line, char *var);
static char	**creat_new_env(int i);

char	**del_one_env(char *var)
{
	int		i;
	char	**new_env;

	i = 0;
	while (g_d.env[i])
	{
		if (cmp_var_and_env(g_d.env[i], var))
		{
			new_env = creat_new_env(i);
			if (!new_env)
				return (NULL);
			return (new_env);
		}
		i++;
	}
	return (NULL);
}

static char	**creat_new_env(int i)
{
	int		i_env;
	int		y;
	int		x;
	int		pos_del;
	char	**new_env;

	i_env = 0;
	pos_del = i;
	x = my_strdlen(g_d.env) - 1;
	new_env = calloc(x + 1, sizeof(char *));
	if (!new_env)
		return (NULL);
	i = 0;
	while (i < x - 1)
	{
		printf("-----> %s\n", g_d.env[i_env]);
		if (i_env == pos_del)
		{
			i_env++;
			continue ;
		}
		y = ft_strlen(g_d.env[i_env]);
		new_env[i] = calloc(y + 1, sizeof(char));
		if (!new_env[i])
			return (NULL);
		ft_strlcpy(new_env[i], g_d.env[i_env], y + 1);
		i++;
		i_env++;
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
