/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:33:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/23 08:49:16 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	print_map(t_map *map);
static void	handler(int sig, siginfo_t *x, void *y);

int	main(int argc, char **argv, char **env)
{
	t_input				input;
	struct sigaction	ssa;

	(void) argc;
	(void) argv;
	ssa.sa_sigaction = &handler;
	ssa.sa_flags = SA_SIGINFO;
	sigemptyset(&ssa.sa_mask);
	sigaction(SIGINT, &ssa, 0);
	sigaction(SIGQUIT, &ssa, 0);
	init_t_g_sig();
	g_d.env = my_strdcpy(env);
	printf("$> pwd\n%s\n", ft_get_env("PWD="));
	printf("%s\n\n", *ft_get_env_start("OLDPWD="));

	printf("$> cd ../minishell_thomas/printf/../../minishell_thomas\n");	
	ft_cd("../minishell_thomas/printf/../../minishell_thomas");
	printf("$> pwd\n%s\n", ft_get_env("PWD="));
	printf("%s\n\n", *ft_get_env_start("OLDPWD="));

	printf("$> cd ../../\n");	
	ft_cd("../../");
	printf("$> pwd\n%s\n", ft_get_env("PWD="));
	printf("%s\n\n", *ft_get_env_start("OLDPWD="));

	printf("$> cd build/\n");
	ft_cd("build/");
	printf("$> pwd\n%s\n", ft_get_env("PWD="));
	printf("%s\n\n", *ft_get_env_start("OLDPWD="));
	
	printf("$> cd ..\n");
	ft_cd("..");
	printf("$> pwd\n%s\n", ft_get_env("PWD="));
	printf("%s\n\n", *ft_get_env_start("OLDPWD="));
	
	printf("$> cd\n");
	ft_cd("");
	printf("$> pwd\n%s\n", ft_get_env("PWD="));
	printf("%s\n\n", *ft_get_env_start("OLDPWD="));

	printf("$> cd\n");
	ft_cd("");
	printf("$> pwd\n%s\n", ft_get_env("PWD="));
	printf("%s\n\n", *ft_get_env_start("OLDPWD="));

	printf("$> cd ..\n");
	ft_cd("..");
	printf("$> pwd\n%s\n", ft_get_env("PWD="));
	printf("%s\n\n", *ft_get_env_start("OLDPWD="));

	printf("$> cd ..\n");
	ft_cd("..");
	printf("$> pwd\n%s\n", ft_get_env("PWD="));
	printf("%s\n\n", *ft_get_env_start("OLDPWD="));

	printf("$> cd ..\n");
	ft_cd("..");
	printf("$> pwd\n%s\n", ft_get_env("PWD="));
	printf("%s\n\n", *ft_get_env_start("OLDPWD="));

	while (1)
	{
		if (g_d.signal > -1)
		{
			write(1, "\n", 1);
			g_d.signal = -1;
		}
		init_input(&input, readline("$> "));
		if (!input.raw)
			continue ;
		lexer(&input, input.raw);
		print_map(input.lexer);
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
	(void) x;
	(void) y;
	if (sig == 2)
	{
		g_d.signal = 2;
	}
	if (sig == 3)
	{
		g_d.signal = 3;
	}
}

static void	print_map(t_map *map)
{
	t_map	*tmp;

	tmp = map;
	while (tmp)
	{
		ft_printf("%d - ", tmp->key);
		if (tmp->key == WORD)
			ft_printf("WORD :", tmp->key);
		else if (tmp->key == SQUOTE)
			ft_printf("SQUOTE :", tmp->key);
		else if (tmp->key == DQUOTE)
			ft_printf("DQUOTE :", tmp->key);
		else if (tmp->key == CMD)
			ft_printf("CMD :", tmp->key);
		else if (tmp->key == DELIM)
			ft_printf("DELIM :", tmp->key);
		else
			ft_printf("NONE :", tmp->key);
		ft_printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}
