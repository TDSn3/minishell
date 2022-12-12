/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:33:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/12 11:45:44 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	first_check(t_input *input);
static void	change_handler_and_start_execute(t_input *input);
static void	init_struct_sigaction(t_input *input, struct sigaction *ssa);
static void	prompt(t_input *input);

int	g_status;

int	main(int argc, char **argv, char **env)
{
	t_input				input;
	struct sigaction	ssa;

	(void) argc;
	(void) argv;
	init_struct_sigaction(&input, &ssa);
	if (copy_env(env, &input) || copy_env_in_export(&input) || shlvl(&input))
		ms_exit(&input, 1);
	prompt(&input);
	free_all(&input);
	return (0);
}

/* ************************************************************************** */
/*																			  */
/*   Terminos et les focntins tc[...] change le comportement du terminal.	  */
/*   Le flag ECHOCTL est activé pour les nouvelles règles du terminal,		  */
/*   il permet ne pas afficher les signaux comme "^C".						  */
/*																			  */
/* ************************************************************************** */
static void	prompt(t_input *input)
{
	struct termios		termios_new;

	tcgetattr(0, &termios_new);
	termios_new.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &termios_new);
	printf("\n\033[36mThe default interactive shell is now");
	printf(" \033[36;01mminishell.\033[00m\n");
	while (1)
	{
		init_input(input, readline("\033[36;01m$> \033[00m"));
		if (!input->raw)
			ms_exit(input, 0);
		if (ft_strlen(input->raw) > 0)
		{
			first_check(input);
			add_history(input->raw);
		}
		free_input(input);
	}
}

static void	first_check(t_input *input)
{
	if (!lexer(input, input->raw))
		return ;
	if (!check_syntax(input))
		return ;
	check_expand(input);
	parser(input);
	change_handler_and_start_execute(input);
}

/* ************************************************************************** */
/*																			  */
/*   Passe le gestionnaire de signaux en non interactif avce handler_off.     */
/*   En mode non interactif, aucun signal n'est interprété.	    			  */
/*   Puis, repasse en mode interactif aprés l'éxecution.					  */
/*																			  */
/* ************************************************************************** */
static void	change_handler_and_start_execute(t_input *input)
{
	input->ssa->sa_handler = &handler_off;
	sigaction(SIGINT, input->ssa, 0);
	sigaction(SIGQUIT, input->ssa, 0);
	if (input->paths)
		execute_cmd(input);
	else
		perror("PATH");
	input->ssa->sa_handler = &handler_on;
	sigaction(SIGINT, input->ssa, 0);
	sigaction(SIGQUIT, input->ssa, 0);
}

static void	init_struct_sigaction(t_input *input, struct sigaction *ssa)
{
	input->env = NULL;
	input->export = NULL;
	input->ssa = ssa;
	input->ssa->sa_handler = &handler_on;
	input->ssa->sa_flags = SA_RESTART;
	sigemptyset(&input->ssa->sa_mask);
	sigaction(SIGINT, input->ssa, 0);
	sigaction(SIGQUIT, input->ssa, 0);
}
