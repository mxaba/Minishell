/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 09:00:02 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/31 09:00:04 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*src2;

	i = 0;
	src2 = (const char*)src;
	dest = (char*)dst;
	while (i < n)
	{
		dest[i] = src2[i];
		i++;
	}
	return (dest);
}
