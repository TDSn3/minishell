/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:37:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/06 23:16:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	child_exec(char *cmd_path, char **argv);

void	execute_cmd(char *cmd, char **argv, t_input *input)
{
	(void) cmd;
	pid_t	pid;
	int		status;
	char	*cmd_path;

	pid = 0;
	if (!argv || !*argv)
		return ;
	if (builtin_chr(argv, input))
	{
		printf("\033[33;03mbuiltin detected\033[00m\n");
		return ;
	}
	cmd_path = cmd_path_chr(argv[0]);
	if (cmd_path)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			if (cmd_path)
				free(cmd_path);
			return ;
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, 0);
			kill(pid, SIGTERM);
		}
		else
			child_exec(cmd_path, argv);
		free(cmd_path);
	}
}

static void	child_exec(char *cmd_path, char **argv)
{
	printf("execve %s\n", cmd_path);
	execve(cmd_path, argv, g_d.env);
}
