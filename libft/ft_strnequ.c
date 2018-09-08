/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 09:58:41 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/31 09:59:27 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;
	size_t s1_len;
	size_t s2_len;

	if (s1 == NULL || s2 == NULL)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	while (i < n || s1[i] || s2[i])
	{
		if (s1_len == s2_len && *s1 == *s2)
			return (1);
		else
			return (0);
		i++;
	}
	return (0);
}
