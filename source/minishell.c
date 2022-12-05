/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:33:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/05 14:08:20 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	handler(int sig, siginfo_t *x, void *y);
static int	ctrl_d(t_input *input);
static void	print_ast(t_list *ast);
static void	exec_all(t_input *input, t_list *ast);

t_gd	g_d;

int	main(int argc, char **argv, char **env)
{
	t_input				input;
	struct sigaction	ssa;
	struct termios		termios_new;

	(void) argc;
	(void) argv;
	ssa.sa_sigaction = &handler;
	ssa.sa_flags = SA_SIGINFO;
	sigemptyset(&ssa.sa_mask);
	sigaction(SIGINT, &ssa, 0);
	sigaction(SIGQUIT, &ssa, 0);
	init_t_gd();
	if (copy_env(env) || copy_env_in_export())
		return (1);
	tcgetattr(0, &termios_new);
	termios_new.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &termios_new);
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
			print_ast(input.ast);
			exec_all(&input, input.ast);
		}
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
static void	handler(int sig, siginfo_t *x, void *y)
{
	int	return_write;

	return_write = 0;
	(void) x;
	(void) y;
	(void) return_write;
	if (sig == 2)
	{
		return_write = write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_d.signal = 2;
	}
	if (sig == 3)
	{
		rl_on_new_line();
		rl_redisplay();
		rl_replace_line("", 0);
		g_d.signal = 3;
	}
}

static int	ctrl_d(t_input *input)
{
	printf("exit\n");
	free_all();
	free_input(input);
	return (0);
}

static void	print_ast(t_list *ast)
{
	t_list	*tmp;
	t_node	*node;

	tmp = ast;
	if (!ast)
		return ;
	while (tmp)
	{
		printf("NEW COMMAND\n");
		node = tmp->content;
		for (size_t i = 0; node->args[i]; i++)
		{
			printf("%ld: %s\n", i, node->args[i]);
		}
		tmp = tmp->next;
	}
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
		execute_cmd(input->raw, node->args);
		tmp = tmp->next;
	}
}
