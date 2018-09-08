/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:55:53 by mxaba             #+#    #+#             */
/*   Updated: 2018/09/07 09:38:52 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_env(void)
{
	int		i;

	i = 0;
	while (g_envp[i])
	{
		ft_putendl(g_envp[i]);
		i++;
	}
}

static int	exec_builtin(char **arg)
{
	if (!arg || arg[0] == NULL)
		return (1);
	else if (ft_strcmp(arg[0], "exit") == 0)
	{
		ft_putendl("LOL you suck, The program is exiting... 100%");
		return (0);
	}
	else if (ft_strcmp(arg[0], "cd") == 0)
		return (ft_cd(arg + 1));
	else if (ft_strcmp(arg[0], "echo") == 0)
		return (ft_echo(arg + 1));
	else if (ft_strcmp(arg[0], "setenv") == 0)
		return (ft_setenv(arg + 1));
	else if (ft_strcmp(arg[0], "unsetenv") == 0)
		return (ft_unsetenv(arg + 1));
	else if (ft_strcmp(arg[0], "env") == 0)
	{
		print_env();
		return (1);
	}
	else
		return (exec_bin(arg));
}

static void	ft_loop(void)
{
	char	*cmd_line;
	char	**arg;
	int		status;

	status = 1;
	while (status)
	{
		ft_putstr("\033[32m$>\033[36m ");
		get_next_line(0, &cmd_line);
		arg = ft_split(cmd_line);
		free(cmd_line);
		status = exec_builtin(arg);
		ft_free_array(arg);
	}
}

static void	copy_envp(int ac, char **av, char **envp)
{
	int		i;

	(void)ac;
	(void)av;
	g_envp = (char **)malloc(sizeof(char *) * (len_of_envp(envp) + 1));
	i = 0;
	while (envp[i])
	{
		if (!(g_envp[i] = ft_strdup(envp[i])))
		{
			ft_free_array(g_envp);
			write(1, "\n", 1);
			exit(0);
		}
		i++;
	}
	g_envp[i] = NULL;
}

int			main(int ac, char **av, char **envp)
{
	copy_envp(ac, av, envp);
	ft_loop();
	ft_free_array(g_envp);
	return (1);
}
