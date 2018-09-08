/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 09:57:31 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/31 09:57:33 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;
	unsigned int len;

	i = 0;
	if (s && f)
	{
		len = ft_strlen(s);
		while (i < len)
		{
			f(i, &s[i]);
			i++;
		}
	}
}
