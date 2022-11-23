/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:17:38 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/23 20:39:27 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	empty_path(char *stock_pwd);
static int	rev_pwd_oldpwd(char *stock_pwd);
static int	print_error(void);

int	ms_cd(const char *path)
{
	int			res;
	char		*path_update;
	char		*stock_pwd;

	stock_pwd = ft_strdup(ms_get_env("PWD="));
	if (!stock_pwd)
		return (print_error());
	path_update = NULL;
	if (!path || !*path)
		return (empty_path(stock_pwd));
	if (ft_strlen(path) == 1 && path[0] == '-')
		return (rev_pwd_oldpwd(stock_pwd));
	if (update_path(path, &path_update))
		return (print_error());
	res = chdir(path_update);
	if (res < 0 || update_env(path_update))
		return (print_error());
	get_oldpwd(stock_pwd);
	return (0);
}

static int	rev_pwd_oldpwd(char *stock_pwd)
{
	int	res;

	res = chdir(ms_get_env("OLDPWD="));
	if (res < 0 || update_env(ms_get_env("OLDPWD=")))
		return (print_error());
	printf("%s\n", ms_get_env("PWD="));
	get_oldpwd(stock_pwd);
	return (0);
}

static int	empty_path(char *stock_pwd)
{
	const char	*str;
	int			res;

	str = (const char *)ms_get_env("HOME=");
	if (str)
	{
		res = chdir(str);
		if (res < 0 || update_env_home(str))
			return (print_error());
	}
	get_oldpwd(stock_pwd);
	return (0);
}

static int	print_error(void)
{
	perror("cd");
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
