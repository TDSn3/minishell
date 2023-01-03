/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:00:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/03 12:42:47 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	exec_cmd(t_input *input, t_list *cmds, char *command);
static int	access_execve(t_input *input, t_list *cmds, char *command);
static void	wait_exec(void);

void	check_cmd(t_input *input, t_list *cmds)
{
	char	*command;
	t_node	*node;

	command = NULL;
	node = cmds->content;
	if (builtin_chr(node, input))
		return ;
	if (node->args && node->args[0])
		command = cmd_path_chr(node->args[0], input);
	exec_cmd(input, cmds, command);
	if (!command)
	{
		if (node->args && node->args[0])
		{
			ft_putstr_fd(node->args[0], 2);
			ft_putstr_fd(": command not found\n", 2);
			g_status = 127;
		}
	}
	free(command);
}

static void	exec_cmd(t_input *input, t_list *cmds, char *command)
{
	int		pid;
	t_node	*node;

	node = cmds->content;
	pid = fork();
	if (pid < 0)
	{
		ft_cmd_error(NULL, "fork");
		free_all(input);
		free_input(input);
		return ;
	}
	if (pid == 0)
	{
		if (ms_redir(node) >= 0)
			access_execve(input, cmds, command);
		free_all(input);
		free_input(input);
		free(command);
		if (g_status == 130)
			exit(130);
		exit(1);
	}
	wait_exec();
}

static void	wait_exec(void)
{
	int	status;

	status = 0;
	wait(&status);
	if (status == 33280)
	{
		g_status = 130;
		return ;
	}
	if (WIFSIGNALED(status))
	{
		if (WCOREDUMP(status))
			ft_putstr_fd("Quit (core dumped)\n", 2);
		g_status = WTERMSIG(status) + 128;
	}
	else if (WEXITSTATUS(status) > 0)
		g_status = WEXITSTATUS(status);
	else
		g_status = 0;
}

static int	access_execve(t_input *input, t_list *cmds, char *command)
{
	t_node	*node;

	node = cmds->content;
	if (!node->args || !node->args[0])
		return (0);
	if (command && access(command, F_OK | X_OK) == 0)
		if (execve(command, node->args, input->env) == -1)
			return (ft_cmd_error(NULL, node->args[0]));
	return (1);
}
