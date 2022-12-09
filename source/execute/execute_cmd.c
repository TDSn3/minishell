/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:37:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/09 14:35:33 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	fork_error(char	*cmd_path);
//static void	handler(int sig);

void	execute_cmd(char *cmd, char **argv, t_input *input)
{
	pid_t	pid;
//	struct sigaction	ssa;
	int		status;
	char	*cmd_path;

//	ssa.sa_handler = &handler;
//	ssa.sa_flags = 0;
//	sigemptyset(&ssa.sa_mask);
//	sigaction(SIGINT, &ssa, 0);
//	sigaction(SIGQUIT, &ssa, 0);
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
			return (fork_error(cmd_path));
		else if (pid > 0)
		{
			g_pid_child[0] = pid;
			waitpid(pid, &status, 0);
			kill(pid, SIGTERM);
		}
		else
			if (execve(cmd_path, argv, input->env) == -1)
				perror("fork");
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
/*
static void	handler(int sig)
{
	int	return_write;

	return_write = 0;
	(void) return_write;
	printf("->%d\n", g_pid_child[0]);
	if (sig == 2)
	{
		return_write = write(1, "\n", 1);
		if (g_pid_child[0] > 0)
			printf("kill: %d\n", kill(g_pid_child[0], SIGINT));
		ft_bzero(g_pid_child, 1024 * sizeof(int));
		return ;
	}
	if (sig == 3)
	{
		return_write = write(1, "\n", 1);
		if (g_pid_child[0] > 0)
			printf("kill: %d\n", kill(g_pid_child[0], SIGQUIT));
		ft_bzero(g_pid_child, 1024 * sizeof(int));
		return ;
	}
}
*/