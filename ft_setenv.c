/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:20:44 by mxaba             #+#    #+#             */
/*   Updated: 2018/09/05 10:57:13 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_setenv(char **arg)
{
	if (!arg[0] || (arg[0] && !arg[1]))
	{
		ft_putendl("setenv: \033[0mtoo few arguments\36m");
		return (1);
	}
	if (arg[0] && arg[1])
	{
		if (arg[2])
		{
			ft_putendl("setenv: \033[0mtoo many arguments\36m");
			return (1);
		}
		set_envp(arg[0], arg[1]);
	}
	return (1);
}
