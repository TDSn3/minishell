/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:40:40 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/07 21:54:09 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	execute_minishell(char *cmd, char **argv, t_input *input);
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
			ms_env(input);
		return (1);
	}
	if (!my_strcmp(argv[0], "pwd"))
	{
		if (size_argv > 1)
			print_error(argv[0], -1);
		else
			ms_pwd(input);
		return (1);
	}
	if (!my_strcmp(argv[0], "cd"))
	{
		if (size_argv > 2)
			print_error(argv[0], -1);
		else
			ms_cd(argv[1], input);
		return (1);
	}
	if (!my_strcmp(argv[0], "export"))
	{
		if (argv[1])
			while (argv[i])
				ms_export(argv[i++], input);
		if (!argv[1])
			ms_export(NULL, input);
		return (1);
	}
	if (!my_strcmp(argv[0], "unset"))
	{
		if (argv[1])
			while (argv[i])
				ms_unset(argv[i++], input);
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
		execute_minishell(ms_get_env("MS_PATH", input) + 1, argv, input);
		return (1);
	}
	return (0);
}

static void	execute_minishell(char *cmd, char **argv, t_input *input)
{
	pid_t	pid;
	int		status;

	pid = 0;
	if (!argv || !*argv)
		return ;
	printf("--->%s\n", cmd);
	if (access(cmd, F_OK | X_OK) == -1)
		return (perror("execute_minishell"));
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
	{
		if (execve(cmd, argv, input->env) == -1)
			ms_exit(input);
	}
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
