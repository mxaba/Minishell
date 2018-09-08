/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 09:12:15 by mxaba             #+#    #+#             */
/*   Updated: 2018/09/05 10:56:12 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_exec(char *path, char **arg)
{
	int			pid;

	pid = fork();
	if (pid == 0)
		execve(path, arg, g_envp);
	else if (pid < 0)
		ft_putendl("unfortunatley it failed");
	wait(&pid);
	return (1);
}

static void	print_error(char *arg)
{
	ft_putstr("$> command not found:");
	ft_putendl(arg);
}

static int	exec_path(char **arg, char **path)
{
	int			i;
	struct stat	fstat;
	char		*tmp;
	char		*tmp2;

	i = -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp2 = ft_strjoin(tmp, arg[0]);
		free(tmp);
		if (lstat(tmp2, &fstat) != -1)
		{
			if (fstat.st_mode & S_IXUSR)
			{
				ft_exec(tmp2, arg);
				free(tmp2);
				return (1);
			}
		}
		free(tmp2);
	}
	return (0);
}

int			exec_bin(char **arg)
{
	char		**path;
	struct stat	fstat;
	int			ret;

	ret = 0;
	if (lstat(arg[0], &fstat) != -1)
	{
		if (fstat.st_mode & S_IXUSR)
		{
			ft_exec(arg[0], arg);
			return (1);
		}
	}
	path = ft_strsplit(find_envp("PATH"), ':');
	if (!path || path[0] == NULL)
		print_error(arg[0]);
	else
	{
		ret = exec_path(arg, path);
		if (ret == 0)
			print_error(arg[0]);
	}
	ft_free_array(path);
	return (1);
}
