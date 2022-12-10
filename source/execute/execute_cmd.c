/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:37:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/10 14:11:45 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	fork_error(char	*cmd_path);

void	execute_cmd(char *cmd, char **argv, t_input *input)
{
	pid_t	pid;
	int		status;
	char	*cmd_path;

	(void) cmd;
	pid = 0;
	status = 0;
	if (!argv || !*argv)
		return ;
	if (builtin_chr(argv, input))
		return ;
	cmd_path = cmd_path_chr(argv[0], input);
	if (cmd_path)
	{
		pid = fork();
		if (pid == -1)
			return (fork_error(cmd_path));
		else if (pid > 0)
		{
			waitpid(pid, &status, 0);
			kill(pid, SIGTERM);
			if (WCOREDUMP(status))
				printf("Quit (core dumped)\n");
			if (WEXITSTATUS(status) == 1)
				g_status = 1;
			else if (WIFSIGNALED(status))
				g_status = WTERMSIG(status) + 128;
			else
				g_status = 0;
			printf("exit_status = %d\n", g_status);
		}
		else
		{
			if (execve(cmd_path, argv, input->env) == -1)
				perror("fork");
			exit(EXIT_FAILURE);
		}
		free(cmd_path);
	}
}

static void	fork_error(char	*cmd_path)
{
	perror("fork");
	if (cmd_path)
		free(cmd_path);
	return ;
}
