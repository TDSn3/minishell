/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:11:03 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/11 01:56:50 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_strlen_stop_nl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

static int	ft_strchr_buffer_nl(char *buffer_p, int i)
{
	size_t	j;
	char	*buffer_start_nl;

	buffer_start_nl = ft_strchr(buffer_p, '\n');
	if (buffer_start_nl || i < 1)
	{
		j = ft_strlen(buffer_start_nl);
		if (j > 1 && i > 0)
			ft_strlcpy(buffer_p, buffer_start_nl + 1, j);
		else
			ft_bzero(buffer_p, BUFFER_SIZE);
		return (1);
	}
	else
		return (0);
}

static int	ft_start_gnl(char *buffer_p, char **str, char **str_three, int *i)
{
	*i = 1;
	*str = 0;
	*str_three = 0;
	if (*buffer_p)
	{
		*str = malloc(ft_strlen_stop_nl(buffer_p) + 1);
		ft_strlcpy(*str, buffer_p, ft_strlen_stop_nl(buffer_p) + 1);
		if (ft_strchr_buffer_nl(buffer_p, *i))
			return (1);
	}
	return (0);
}

static int	ft_in_while(char *buffer_p, char **str, char **str_three, int i)
{	
	char	*str_two;

	if (i < BUFFER_SIZE)
		ft_bzero(buffer_p + i, BUFFER_SIZE - i);
	if (!*str)
	{
		*str = malloc(ft_strlen_stop_nl(buffer_p) + 1);
		ft_strlcpy(*str, buffer_p, ft_strlen_stop_nl(buffer_p) + 1);
		if (ft_strchr_buffer_nl(buffer_p, i))
			return (1);
	}
	else
	{
		str_two = malloc(ft_strlen_stop_nl(buffer_p) + 1);
		ft_strlcpy(str_two, buffer_p, ft_strlen_stop_nl(buffer_p) + 1);
		*str_three = ft_strjoin (*str, str_two);
		free(*str);
		free(str_two);
		*str = *str_three;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*str;
	char		*str_three;
	int			i;

	if (BUFFER_SIZE == 0 || read(fd, buffer[fd], 0) == -1)
		return (NULL);
	if (ft_start_gnl(buffer[fd], &str, &str_three, &i))
		return (str);
	while (i <= BUFFER_SIZE && i > 0)
	{
		i = read(fd, buffer[fd], BUFFER_SIZE);
		if (i > BUFFER_SIZE || i < 1)
			break ;
		if (ft_in_while(buffer[fd], &str, &str_three, i))
			return (str);
		if (ft_strchr(buffer[fd], '\n') || i < 1)
			break ;
	}
	if (ft_strchr_buffer_nl(buffer[fd], i) && i == 0)
		return (str);
	return (str_three);
}
