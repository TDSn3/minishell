/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:37:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/04 17:15:02 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	child_exec(char *cmd_path, t_node *node);

void	execute_cmd(char *cmd, t_node *node)
{
	(void) cmd;
	pid_t	pid;
	int		status;
	char	*cmd_path;

	pid = 0;
	if (!cmd || !*cmd)
		return ;
	cmd_path = cmd_path_chr(cmd);
	if (cmd_path)
		printf("%s\n", cmd_path);
	if (cmd_path)
		free(cmd_path);
	if (cmd_path)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			return ;
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, 0);
			kill(pid, SIGTERM);
		}
		else
			child_exec(cmd_path);
	}
}

static void	child_exec(char *cmd_path, t_node *node)
{
	printf("execve %s\n", cmd_path);
	execve(cmd_path, node->args, g_d.env);
}
