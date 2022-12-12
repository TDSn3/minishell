/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:18:20 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/12 21:34:34 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	ft_heredoc(char *file, char *limit)
{
	char	*input;
	int		heredoc;

	heredoc = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	input = NULL;
	while (1)
	{
		write(1, "> ", 2);
		input = get_next_line(0);
		if (input && ft_strncmp(limit, input, ft_strlen(limit)))
			write(heredoc, input, ft_strlen(input));
		else
			break ;
		free(input);
	}
	if (input)
		free(input);
	close(heredoc);
}

static int	g_redir(t_redir *redir, int status, int todup)
{
	int	infile;

	infile = -1;
	if (status)
	{
		ft_heredoc("/tmp/heredoc", redir->file);
		infile = open("/tmp/heredoc", O_RDONLY);
	}
	else
		infile = open(redir->file, O_RDONLY);
	if (infile == -1)
		return (0);
	if (todup)
	{
		if (dup2(infile, STDIN_FILENO) == -1)
			return (0);
	}
	close(infile);
	return (1);
}

static int	d_redir(char *file, int status, int todup)
{
	int	outfile;

	if (status)
		outfile = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		outfile = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile == -1)
		return (0);
	if (todup)
	{
		if (dup2(outfile, STDOUT_FILENO) == -1)
			return (0);
	}
	close(outfile);
	return (1);
}

static int	ft_redirect(t_node *node, int todup)
{
	t_redir	*redir;
	t_list	*r;
	int		res;

	res = 1;
	r = node->redir;
	while (r)
	{
		redir = r->content;
		if (redir->type == 1)
			res = g_redir(redir, 0, todup);
		if (redir->type == 11)
			res = g_redir(redir, 1, todup);
		if (redir->type == 2)
			res = d_redir(redir->file, 0, todup);
		if (redir->type == 22)
			res = d_redir(redir->file, 1, todup);
		if (res != 1)
		{
			perror(node->args[0]);
			return (0);
		}
		r = r->next;
	}
	return (1);
}

void	ms_redir(t_input *input, t_node *node)
{
	int		todup;

	todup = 1;
	if (!node->args || !node->args[0])
		todup = 0;
	if (!ft_redirect(node, todup))
		return ;
	(void) input;
}
