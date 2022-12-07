/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:40:40 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/07 10:59:13 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	execute_minishell(char *cmd, char **argv);
static int	print_error(char *cmd, int nb_error);

int	builtin_chr(char **argv, t_input *input)
{
	int		i;
	size_t	size_argv;

	i = 1;
	size_argv = my_strdlen(argv);
	if (!my_strcmp(argv[0], "env"))
	{
		if (size_argv > 1)
			print_error(argv[0], -1);
		else
			ms_env();
		return (1);
	}
	if (!my_strcmp(argv[0], "pwd"))
	{
		if (size_argv > 1)
			print_error(argv[0], -1);
		else
			ms_pwd();
		return (1);
	}
	if (!my_strcmp(argv[0], "cd"))
	{
		if (size_argv > 2)
			print_error(argv[0], -1);
		else
			ms_cd(argv[1]);
		return (1);
	}
	if (!my_strcmp(argv[0], "export"))
	{
		if (argv[1])
			while (argv[i])
				ms_export(argv[i++]);
		if (!argv[1])
			ms_export(NULL);
		return (1);
	}
	if (!my_strcmp(argv[0], "unset"))
	{
		if (argv[1])
			while (argv[i])
				ms_unset(argv[i++]);
		return (1);
	}
	if (!my_strcmp(argv[0], "echo"))
	{
		ms_echo(argv);
		return (1);
	}
	if (!my_strcmp(argv[0], "exit"))
	{
		ms_exit(input);
		return (1);
	}
	if (!my_strcmp(argv[0], "minishell"))
	{
		execute_minishell(ms_get_env("MS_PATH") + 1, argv);
		return (1);
	}
	return (0);
}

static void	execute_minishell(char *cmd, char **argv)
{
	pid_t	pid;
	int		status;

	pid = 0;
	if (!argv || !*argv)
		return ;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		if (cmd)
			free(cmd);
		return ;
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else
		execve(cmd, argv, g_d.env);
}

static int	print_error(char *cmd, int nb_error)
{
	if (nb_error == -1)
		printf("%s: too many arguments\n", cmd);
	else
	{
		errno = nb_error;
		perror("export");
	}
	return (1);
}
