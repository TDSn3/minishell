/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clone_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:28:30 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/16 16:34:10 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	save_redir(t_node *node, t_input *input)
{
	int	redir;

	if (node->redir)
	{
		input->fdin = dup(0);
		input->fdout = dup(1);
		redir = ms_redir(node);
		if (redir < 0)
			return (0);
		return (redir);
	}
	return (0);
}

void	restore_redir(t_input *input, int redir)
{
	if (redir < 0)
		return ;
	if (redir == 0 || redir == 2)
	{
		if (dup2(input->fdin, STDIN_FILENO) == -1)
			return ;
		close(input->fdin);
		input->fdin = -1;
	}
	if (redir == 1 || redir == 2)
	{
		if (dup2(input->fdout, STDOUT_FILENO) == -1)
			return ;
		close(input->fdout);
		input->fdout = -1;
	}
}

int	is_differ(char *input, char *limit)
{
	size_t	len;
	char	*tmp;

	if (input)
	{
		len = ft_strlen(input);
		tmp = ft_strdup(input);
		if (!tmp)
		{
			ft_putstr_fd("memory fail\n", 2);
			return (0);
		}
		tmp[len - 1] = 0;
		if (my_strcmp(limit, tmp))
		{
			free(tmp);
			return (1);
		}
		free(tmp);
		return (0);
	}
	return (0);
}

void	ft_heredoc(char *file, char *limit)
{
	char				*input;
	int					heredoc;
	struct sigaction	ssa_h;

	ssa_h.sa_handler = &handler_herdoc;
	ssa_h.sa_flags = SA_RESTART;
	sigemptyset(&ssa_h.sa_mask);
	sigaction(SIGINT, &ssa_h, 0);
	sigaction(SIGQUIT, &ssa_h, 0);
	heredoc = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	input = NULL;
	while (1)
	{
		write(1, "> ", 2);
		input = get_next_line(0);
		if (is_differ(input, limit))
			write(heredoc, input, ft_strlen(input));
		else
			break ;
		free(input);
	}
	if (input)
		free(input);
	close(heredoc);
}
