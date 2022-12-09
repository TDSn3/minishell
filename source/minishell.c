/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:33:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/09 05:36:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	handler(int sig);
static void	handler_off(int sig);
static int	ctrl_d(t_input *input);
static void	exec_all(t_input *input, t_list *ast);

int	main(int argc, char **argv, char **env)
{
	t_input				input;
	struct sigaction	ssa;
	struct termios		termios_new;

	(void) argc;
	(void) argv;
	input.env = NULL;
	input.export = NULL;
	ssa.sa_handler = &handler;
	ssa.sa_flags = 0;
	sigemptyset(&ssa.sa_mask);
	sigaction(SIGINT, &ssa, 0);
	sigaction(SIGQUIT, &ssa, 0);
	if (copy_env(env, &input) || copy_env_in_export(&input)
		|| shlvl(&input) || ms_path_var(argv, &input))
		return (1);
	tcgetattr(0, &termios_new);
	termios_new.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &termios_new);
	printf("\n\033[36mThe default interactive shell is now");
	printf(" \033[36;01mminishell.\033[00m\n");
	while (1)
	{
		init_input(&input, readline("\033[36;01m$> \033[00m"));
		if (!input.raw)
			exit (ctrl_d(&input));
		if (ft_strlen(input.raw) > 0)
		{
			lexer(&input, input.raw);
			check_syntax(&input);
			check_expand(&input);
			parser(&input);
			ssa.sa_handler = &handler_off;
			sigaction(SIGINT, &ssa, 0);
			sigaction(SIGQUIT, &ssa, 0);
			exec_all(&input, input.ast);
			ssa.sa_handler = &handler;
			sigaction(SIGINT, &ssa, 0);
			sigaction(SIGQUIT, &ssa, 0);
		}
		if (input.raw && input.raw[0])
			add_history(input.raw);
		free_input(&input);
	}
	return (0);
}

/* ************************************************************************** */
/*																			  */
/*   sig == 2 | SIGINT	| ctrl+c											  */
/*   sig == 3 | SIGQUIT	| ctrl+\											  */
/*																			  */
/* ************************************************************************** */
static void	handler(int sig)
{
	int	return_write;

	return_write = 0;
	(void) return_write;
	if (sig == 2)
	{
		return_write = write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
		rl_replace_line("", 0);
	}
	if (sig == 3)
	{
		rl_on_new_line();
		rl_redisplay();
		rl_replace_line("", 0);
	}
}

static void	handler_off(int sig)
{
	if (sig == 2)
		return ;
	if (sig == 3)
		return ;
}

static int	ctrl_d(t_input *input)
{
	printf("exit\n");
	free_all(input);
	free_input(input);
	return (0);
}

static void	exec_all(t_input *input, t_list *ast)
{
	t_list	*tmp;
	t_node	*node;

	tmp = ast;
	if (!ast)
		return ;
	while (tmp)
	{
		node = tmp->content;
		execute_cmd(input->raw, node->args, input);
		tmp = tmp->next;
	}
}
