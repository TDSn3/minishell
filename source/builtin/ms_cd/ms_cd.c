/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:17:38 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/13 14:17:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	empty_path(char *stock_pwd, t_input *input);
static int	rev_pwd_oldpwd(char *stock_pwd, t_input *input);
static int	print_error(int nb_error, char *path_update);

int	ms_cd(const char *path, t_input *input)
{
	int		res;
	char	pwd[4096];
	char	*path_update;

	if (path && !*path)
		return (0);
	if ((!path) && !ms_get_env("HOME", input))
		return (print_error(-1, NULL));
	path_update = NULL;
	getcwd(pwd, 4096);
	if (!path)
		return (empty_path(pwd, input));
	if (ft_strlen(path) == 1 && path[0] == '-')
		return (rev_pwd_oldpwd(pwd, input));
	if (update_path(path, &path_update, input))
		return (print_error(12, path_update));
	res = chdir(path_update);
	if (res < 0)
		return (print_error(2, path_update));
	if (update_env(path_update, input))
		return (print_error(12, path_update));
	if (get_oldpwd(pwd, input))
		return (print_error(12, path_update));
	free(path_update);
	return (0);
}

static int	rev_pwd_oldpwd(char *stock_pwd, t_input *input)
{
	int		res;
	char	pwd[4096];
	char	*oldpwd;

	res = 0;
	getcwd(pwd, 4096);
	oldpwd = ms_get_env("OLDPWD", input);
	if (oldpwd)
		res = chdir(oldpwd);
	if (!oldpwd || res < 0)
		return (print_error(-2, NULL));
	if (update_env(oldpwd, input))
		return (print_error(12, NULL));
	printf("%s\n", pwd);
	if (get_oldpwd(stock_pwd, input))
		return (print_error(12, NULL));
	return (0);
}

static int	empty_path(char *stock_pwd, t_input *input)
{
	const char	*str;
	int			res;

	str = (const char *)ms_get_env("HOME", input);
	if (str)
	{
		res = chdir(str);
		if (res < 0)
			return (print_error(2, NULL));
		if (update_env_home(str, input))
			return (print_error(12, NULL));
		if (get_oldpwd(stock_pwd, input))
			return (print_error(12, NULL));
		return (0);
	}
	return (print_error(-1, NULL));
}

static int	print_error(int nb_error, char *path_update)
{
	errno = nb_error;
	if (nb_error == -1)
		printf("cd: HOME not set\n");
	else if (nb_error == -2)
		printf("cd: OLDPWD not set\n");
	else
		perror("cd");
	if (path_update)
		free(path_update);
	return (1);
}

/*	Tests pour le main
	printf("\033[36;01m$> \033[00mpwd\n%s\n", ms_get_env("PWD="));
	printf("\033[30m%s\033[00m\n\n", *ms_get_env_start("OLDPWD="));

	printf("\033[36;01m$> \033[00mcd ../minishell_thomas/
	././../minishell_thomas/./\n");	
	ft_cd("../minishell_thomas/././../minishell_thomas/./");
	printf("\033[36;01m$> \033[00mpwd\n%s\n", ms_get_env("PWD="));
	printf("\033[30m%s\033[00m\n\n", *ms_get_env_start("OLDPWD="));

	printf("\033[36;01m$> \033[00mcd ././\n");	
	ft_cd("././");
	printf("\033[36;01m$> \033[00mpwd\n%s\n", ms_get_env("PWD="));
	printf("\033[30m%s\033[00m\n\n", *ms_get_env_start("OLDPWD="));

	printf("\033[36;01m$> \033[00mcd ../../\n");	
	ft_cd("../../");
	printf("\033[36;01m$> \033[00mpwd\n%s\n", ms_get_env("PWD="));
	printf("\033[30m%s\033[00m\n\n", *ms_get_env_start("OLDPWD="));
	
	printf("\033[36;01m$> \033[00mcd ..\n");
	ft_cd("..");
	printf("\033[36;01m$> \033[00mpwd\n%s\n", ms_get_env("PWD="));
	printf("\033[30m%s\033[00m\n\n", *ms_get_env_start("OLDPWD="));
	
	printf("\033[36;01m$> \033[00mcd\n");
	ft_cd("");
	printf("\033[36;01m$> \033[00mpwd\n%s\n", ms_get_env("PWD="));
	printf("\033[30m%s\033[00m\n\n", *ms_get_env_start("OLDPWD="));

	printf("\033[36;01m$> \033[00mcd -\n");	
	ft_cd("-");
	printf("\033[36;01m$> \033[00mpwd\n%s\n", ms_get_env("PWD="));
	printf("\033[30m%s\033[00m\n\n", *ms_get_env_start("OLDPWD="));

	printf("\033[36;01m$> \033[00mcd -\n");	
	ft_cd("-");
	printf("\033[36;01m$> \033[00mpwd\n%s\n", ms_get_env("PWD="));
	printf("\033[30m%s\033[00m\n\n", *ms_get_env_start("OLDPWD="));

	printf("\033[36;01m$> \033[00mcd\n");
	ft_cd("");
	printf("\033[36;01m$> \033[00mpwd\n%s\n", ms_get_env("PWD="));
	printf("\033[30m%s\033[00m\n\n", *ms_get_env_start("OLDPWD="));

	printf("\033[36;01m$> \033[00mcd ..\n");
	ft_cd("..");
	printf("\033[36;01m$> \033[00mpwd\n%s\n", ms_get_env("PWD="));
	printf("\033[30m%s\033[00m\n\n", *ms_get_env_start("OLDPWD="));

	printf("\033[36;01m$> \033[00mcd ..\n");
	ft_cd("..");
	printf("\033[36;01m$> \033[00mpwd\n%s\n", ms_get_env("PWD="));
	printf("\033[30m%s\033[00m\n\n", *ms_get_env_start("OLDPWD="));

	printf("\033[36;01m$> \033[00mcd ..\n");
	ft_cd("..");
	printf("\033[36;01m$> \033[00mpwd\n%s\n", ms_get_env("PWD="));
	printf("\033[30m%s\033[00m\n\n", *ms_get_env_start("OLDPWD="));
*/
