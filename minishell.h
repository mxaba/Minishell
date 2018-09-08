/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 08:30:17 by mxaba             #+#    #+#             */
/*   Updated: 2018/09/07 09:15:09 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "./libft/libft.h"

char **g_envp;

int		exec_bin(char **arg);
int		len_of_envp(char **envp);
int		ft_echo(char **arg);
int		ft_setenv(char **arg);
int		ft_unsetenv(char **arg);
char	*find_envp(char *str);
int		find_position(char *str);
int		ft_cd(char **arg);
void	set_envp(char *arg, char *value);

#endif
