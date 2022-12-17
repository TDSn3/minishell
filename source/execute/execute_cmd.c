/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:48:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/16 16:35:39 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	fork_pipes(t_input *input, t_list *cmds, int *fdin, int count);

void	execute(t_input *input)
{
	t_list	*cmds;
	size_t	size;

	cmds = input->ast;
	size = ft_lstsize(cmds);
	if (size == 1)
		check_cmd(input, cmds);
	else if (size > 1)
	{
		input->pids = (int *) ft_calloc(size, sizeof(int));
		if (!input->pids)
			return ;
		exec_pipe(input, cmds, size);
	}
	else
		return ;
}

void	exec_pipe(t_input *input, t_list *cmds, size_t size)
{
	size_t	count;
	int		in;

	in = 0;
	count = 0;
	while (cmds && count < size)
	{
		if (!fork_pipes(input, cmds, &in, count))
			return ;
		cmds = cmds->next;
		count ++;
	}
	wait_pipes(input->pids, size);
}

int	fork_pipes(t_input *input, t_list *cmds, int *fdin, int count)
{
	int	fd[2];
	int	tmp;

	fd[0] = 0;
	if (cmds->next && pipe(fd) < 0)
		return (0);
	tmp = fd[0];
	fd[0] = *fdin;
	if (!cmds->next)
		fd[1] = 1;
	input->pids[count] = fork();
	if (input->pids[count] < 0)
	{
		ft_cmd_error(cmds, "pids");
		return (0);
	}
	else if (input->pids[count] == 0)
	{
		close(tmp);
		pipe_child(input, cmds, fd);
	}
	ft_close_pipes(fd);
	*fdin = tmp;
	return (1);
}
