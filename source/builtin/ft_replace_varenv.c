/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_varenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:15:58 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/17 04:16:19 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	ft_replace_varenv(char **env, char *var, char *newvar)
{
	size_t	count;
	char	*tmp;

	count = 0;
	if (!env)
		return ;
	while (env[count])
	{
		if (ft_findstr(env[count], var))
		{
			tmp = ft_strjoin(var, "=");
			free(env[count]);
			env[count] = NULL;
			env[count] = ft_strjoin(tmp, newvar);
			free(tmp);
		}
		count ++;
	}
}
