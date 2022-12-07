/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:37:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/07 15:52:26 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	execute_cmd(char *cmd, char **argv, t_input *input)
{
	pid_t	pid;
	int		status;
	char	*cmd_path;

	(void) cmd;
	pid = 0;
	if (!argv || !*argv)
		return ;
	if (builtin_chr(argv, input))
		return ;
	cmd_path = cmd_path_chr(argv[0], input);
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
			execve(cmd_path, argv, input->env);
		free(cmd_path);
	}
}
