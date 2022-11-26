/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:37:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/26 21:50:49 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	execute_cmd(char *cmd)
{
	pid_t	pid;
	char	*cmd_path;

	pid = 0;
	if (cmd && *cmd)
	{
		cmd_path = cmd_path_chr(cmd);
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
				waitpid(pid, NULL, 0);
				kill(pid, SIGTERM);
			}
			else
			{
				printf("execve %s\n", cmd_path);
				execve(cmd_path, NULL, g_d.env);
			}
		}
	}
}