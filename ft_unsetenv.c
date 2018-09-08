/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:20:44 by mxaba             #+#    #+#             */
/*   Updated: 2018/09/05 10:57:13 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**reallocate_env(int new_size)
{
	char    **new_env;
	int             i;

	i = -1;
	new_env = (char**)malloc(sizeof(char*) * (new_size + 1));
	while (g_envp[++i] && i < new_size)
	{
		new_env[i] = ft_strdup(g_envp[i]);
		free(g_envp[i]);
	}
	free(g_envp);
	new_env[i] = NULL;
	return (new_env);
}

static void	remove_envp(int var_pos)
{
	int	i;
	int	var_count;

	free(g_envp[var_pos]);
	g_envp[var_pos] = NULL;
	i = var_pos;
	var_count = var_pos + 1;
	while (g_envp[i + 1])
	{
		g_envp[i] = ft_strdup(g_envp[i + 1]);
		free(g_envp[i + 1]);
		i++;
		var_count++;
	}
	g_envp = reallocate_env(var_count - 1);
}

int		ft_unsetenv(char **arg)
{
	int	i;
	int	var_pos;

	i = 0;
	if (!arg[0])
	{
		ft_putendl("unsetenv: try to pass something");
		return (1);
	}
	while (arg[i])
	{
		var_pos = find_position(arg[i]);
		if (g_envp[var_pos])
			remove_envp(var_pos);
		i++;
	}
	return (1);
}
