/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:17:38 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/09 04:53:19 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	empty_path(char *stock_pwd, t_input *input);
static int	rev_pwd_oldpwd(char *stock_pwd, t_input *input);
static int	print_error(int nb_error, char *path_update);

int	ms_cd(const char *path, t_input *input)
{
	int			res;
	char		*path_update;
	char		*stock_pwd;

	if ((!path || !*path) && !ms_get_env("HOME", input))
		return (print_error(-1, NULL));
	path_update = NULL;
	stock_pwd = ft_strdup(ms_get_env("PWD", input));
	if (!stock_pwd)
		return (print_error(12, path_update));
	path_update = NULL;
	if (!path || !*path)
		return (empty_path(stock_pwd, input));
	if (ft_strlen(path) == 1 && path[0] == '-')
		return (rev_pwd_oldpwd(stock_pwd, input));
	if (update_path(path, &path_update, input))
		return (print_error(12, path_update));
	res = chdir(path_update);
	if (res < 0)
		return (print_error(2, path_update));
	if (update_env(path_update, input))
		return (print_error(12, path_update));
	if (get_oldpwd(stock_pwd, input))
		return (print_error(12, path_update));
	free(path_update);
	return (0);
}

static int	rev_pwd_oldpwd(char *stock_pwd, t_input *input)
{
	int	res;

	res = chdir(ms_get_env("OLDPWD", input));
	if (res < 0)
		return (print_error(2, NULL));
	if (update_env(ms_get_env("OLDPWD", input), input))
		return (print_error(12, NULL));
	printf("%s\n", ms_get_env("PWD", input));
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
