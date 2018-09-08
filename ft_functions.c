/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 10:32:09 by mxaba             #+#    #+#             */
/*   Updated: 2018/09/05 11:45:47 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			find_position(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	while (g_envp[i])
	{
		temp = ft_strjoin(str, "=");
		if (ft_startwith(g_envp[i], temp))
		{
			free(temp);
			return (i);
		}
		free(temp);
		i++;
	}
	return (i);
}

static char	**allocate_envp(int new_pos)
{
	char	**new_envp;
	int		i;

	i = -1;
	new_envp = (char **)malloc(sizeof(char *) * (new_pos + 1));
	while (g_envp[++i] && i < new_pos)
	{
		new_envp[i] = ft_strdup(g_envp[i]);
		free(g_envp[i]);
	}
	free(g_envp[i]);
	return (new_envp);
}

void		set_envp(char *str, char *value)
{
	int		pos;
	char	*temp;

	pos = find_position(str);
	temp = ft_strjoin("=", value);
	if (g_envp[pos])
	{
		free(g_envp[pos]);
		if (value)
			g_envp[pos] = ft_strjoin(str, temp);
	}
	else
	{
		g_envp = allocate_envp(pos + 1);
		if (value)
			g_envp[pos] = ft_strjoin(str, temp);
		g_envp[pos + 1] = NULL;
	}
	free(temp);
}

char		*find_envp(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	while (g_envp[i])
	{
		temp = ft_strjoin(str, "=");
		if (ft_startwith(g_envp[i], temp))
		{
			free(temp);
			return (ft_strchr(g_envp[i], '=') + 1);
		}
		free(temp);
		i++;
	}
	return (NULL);
}

int			len_of_envp(char **envp)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (envp[i])
	{
		len++;
		i++;
	}
	return (len);
}
