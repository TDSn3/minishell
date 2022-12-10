/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:18:20 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/10 21:01:08 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	ft_redirect(t_input *input, t_node *node, int todup);
static int	g_redir(t_input *input, t_redir *redir, int status, int todup);
static void	ft_heredoc(char *file, char *limit);
static int	d_redir(t_input *input, char *file, int status, int todup);

void	ms_redir(t_input *input)
{
	t_list	*ast;
	t_node	*node;
	int		todup;

	ast = input->ast;
	todup = 1;
	while (ast)
	{
		node = ast->content;
		if (!node->args || !node->args[0])
			todup = 0;
		if (!ft_redirect(input, node, todup))
			return ;
		ast = ast->next;
	}
}

static int	ft_redirect(t_input *input, t_node *node, int todup)
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
			res = g_redir(input, redir, 0, todup);
		if (redir->type == 11)
			res = g_redir(input, redir, 1, todup);
		if (redir->type == 2)
			res = d_redir(input, redir->file, 0, todup);
		if (redir->type == 22)
			res = d_redir(input, redir->file, 1, todup);
		if (res != 1)
		{
			perror("redirection ");
			return (0);
		}
		r = r->next;
	}
	return (1);
}

static int	g_redir(t_input *input, t_redir *redir, int status, int todup)
{
	int	infile;

	infile = -1;
	if (status)
	{
		ft_heredoc(".heredoc", redir->file);
		infile = open(".heredoc", O_RDONLY);
	}
	else
		infile = open(redir->file, O_RDONLY);
	if (infile == -1)
		return (0);
	if (todup)
	{
		if (dup2(infile, input->fdin) == -1)
			return (0);
	}
	close(infile);
	(void) input;
	return (1);
}

static int	d_redir(t_input *input, char *file, int status, int todup)
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
		if (dup2(outfile, input->fdout) == -1)
			return (0);
	}
	close(outfile);
	return (1);
}

static void	ft_heredoc(char *file, char *limit)
{
	char	*input;
	int		heredoc;

	heredoc = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		write(1, "> ", 2);
		input = get_next_line(0);
		if (!input || !ft_strncmp(input, limit, ft_strlen(limit) + 1))
			break ;
		write(heredoc, input, ft_strlen(input));
		free(input);
	}
	free(input);
	close(heredoc);
}
