/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 01:13:50 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/09 04:13:33 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	free_function_all(char *stock, char ***stock_two, char *path);

int	creat_pwd(t_input *input)
{
	int		fd;
	char	buff[PATH_MAX];
	char	*stock;
	char	**stock_two;
	char	*path;

	stock = NULL;
	stock_two = NULL;
	path = NULL;
	if (!ms_get_env("PWD", input))
	{
		stock = ft_strjoin("PWD=", getcwd(buff, PATH_MAX));
		if (!stock)
			return (1);
		if (ms_export(stock, input))
			return (free_function_all(stock, &stock_two, path));
	}
	free_function_all(stock, &stock_two, path);
	if (!ms_get_env("PATH", input))
	{
		fd = open("/etc/environment", O_RDONLY);
		if (fd == -1)
			return (free_function_all(stock, &stock_two, path));
		stock = get_next_line(fd);
		if (!stock)
			return (free_function_all(stock, &stock_two, path));
		stock_two = ft_split(stock, '"');
		if (!stock_two)
			return (free_function_all(stock, &stock_two, path));
		if (stock_two[0] && stock_two[1])
			path = ft_strjoin(stock_two[0], stock_two[1]);
		else
			return (free_function_all(stock, &stock_two, path));
		if (ms_export(path, input))
			return (free_function_all(stock, &stock_two, path));
	}
	free_function_all(stock, &stock_two, path);
	return (0);
}

static int	free_function_all(char *stock, char ***stock_two, char *path)
{
	int	i;

	i = 0;
	if (stock_two && *stock_two && **stock_two)
		while ((*stock_two)[i])
			free((*stock_two)[i++]);
	if (stock_two && *stock_two)
		free(*stock_two);
	if (stock)
		free(stock);
	if (path)
		free(path);
	return (1);
}
