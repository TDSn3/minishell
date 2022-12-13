/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_one_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:00:55 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/13 14:12:52 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	chr_and_exec(t_input *input, t_list *cmds);

void	execute_one_cmd(t_input *input, t_list *cmds)
{
	int		pid;
	int		status;
	t_node	*node;

	status = 0;
	node = cmds->content;
	if (builtin_chr(node, input))
	{
	//	close(STDIN_FILENO);
	//	close(STDOUT_FILENO);
		return ;
	}
	pid = fork();
	if (pid < 0)
	{
		ft_cmd_error(input, NULL, "fork");
		free_all(input);
		free_input(input);
		return ;
	}
	if (pid == 0)
	{
		ms_redir(input, node);
		chr_and_exec(input, cmds);
		free_all(input);
		free_input(input);
		close(0);
		close(1);
		exit(1);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			g_status = WEXITSTATUS(status);
		if (WIFSIGNALED(status))
			if (WCOREDUMP(status))
				printf("Quit (core dumped)\n");
		if (WEXITSTATUS(status) == 1)
			g_status = 1;
		else if (WIFSIGNALED(status))
			g_status = WTERMSIG(status) + 128;
		else
			g_status = 0;
	}
}

static int	chr_and_exec(t_input *input, t_list *cmds)
{
	char	*command;
	t_node	*node;

	node = cmds->content;
	if (!node->args || !node->args[0])
		return (0);
	command = cmd_path_chr(node->args[0], input);
	if (!command)
		return (0);
	if (access(command, F_OK | X_OK) == 0)
	{
		if (execve(command, node->args, input->env) == -1)
		{
			free(command);
			return (ft_cmd_error(input, NULL, node->args[0]));
		}
	}
	free(command);
	return (1);
}
