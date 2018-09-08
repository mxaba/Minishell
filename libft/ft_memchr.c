/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 08:38:00 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/31 08:59:49 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	c2;

	s2 = (unsigned char*)s;
	c2 = (unsigned char)c;
	while (n > 0)
	{
		if (*s2 != c2)
		{
			s2++;
		}
		else
			return (s2);
		n--;
	}
	return (NULL);
}
