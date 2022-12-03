/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:33:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/02 16:21:01 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	print_type(t_type type);
void	print_map(t_map *map);
void	print_ast(t_list *ast);
static void	handler(int sig, siginfo_t *x, void *y);

t_gd	g_d;

void	test_lexer(t_input *input)
{
	lexer(input, input->raw);
	check_syntax(input);
	check_expand(input);
	print_map(input->parser);
}

void	test_ast(t_input *input)
{
	parser(input);
	print_ast(input->ast);
}

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
	ms_pwd();
	ms_cd("../test name dir espace");
	ms_pwd();
	(void) input;
//	while (1)
//	{
//		init_input(&input, readline("\033[36;01m$> \033[00m"));
//		if (!input.raw)
//		{
//			printf("exit\n");
//			exit (0);
//		}
////		execute_cmd(input.raw);
//		lexer(&input, input.raw);
//		check_syntax(&input);
//		check_expand(&input);
//		// parser(&input)
//		// print_ast(input.ast);
//		print_map(input.lexer);
//		free_input(&input);
//	}


//	MAIN D'EMILIE
//	while (1)
//	{
//		init_input(&input, readline("minishell: "), env);
//		if (!input.raw)
//		{
//			printf("exit\n");
//			exit (0);
//		}
//		if (ft_strlen(input.raw) > 0)
//		{
//			test_lexer(&input);
//			test_ast(&input);
//			printf("\n");
//		}
////	free_input(&input);
//	}
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
	(void) x;
	(void) y;
	if (sig == 2)
	{
		write(1, "\n", 1);
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

void	print_type(t_type type)
{
	printf("\n");
	if (type == WORD)
		printf("WORD");
	if (type == DQUOTE)
		printf("DQUOTE");
	if (type == SQUOTE)
		printf("SQUOTE");
	if (type == DOLLAR)
		printf("DOLLAR");
	if (type == ESPACE)
		printf("ESPACE");
	if (type == PIPE)
		printf("PIPELINE");
	if (type == GREDIR)
		printf("GREDIR");
	if (type == DREDIR)
		printf("DREDIR");
	if (type == GRREDIR)
		printf("GRREDIR");
	if (type == DRREDIR)
		printf("DRREDIR");
}

void	print_map(t_map *map)
{
	t_map	*tmp;

	tmp = map;
	while (tmp)
	{
		print_type(tmp->type);
		printf(" %d: ", tmp->key);
		printf(" len = %ld: ", ft_strlen(tmp->content));
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}

void	print_ast(t_list *ast)
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

//static void	print_map(t_map *map)
//{
//	t_map	*tmp;
//
//	tmp = map;
//	while (tmp)
//	{
//		ft_printf("%d - ", tmp->key);
//		if (tmp->key == WORD)
//			ft_printf("WORD :", tmp->key);
//		else if (tmp->key == SQUOTE)
//			ft_printf("SQUOTE :", tmp->key);
//		else if (tmp->key == DQUOTE)
//			ft_printf("DQUOTE :", tmp->key);
//		else if (tmp->key == CMD)
//			ft_printf("CMD :", tmp->key);
//		else if (tmp->key == DELIM)
//			ft_printf("DELIM :", tmp->key);
//		else
//			ft_printf("NONE :", tmp->key);
//		ft_printf("%s\n", tmp->content);
//		tmp = tmp->next;
//	}
//}
