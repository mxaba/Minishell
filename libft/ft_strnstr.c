/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 09:59:42 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/31 09:59:48 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (big[i] != '\0')
	{
		j = i;
		k = 0;
		if (little[k] == '\0')
			return ((char*)&big[i]);
		while (big[j] && little[k] && big[j] == little[k] && j < len)
		{
			j++;
			k++;
			if (little[k] == '\0')
				return ((char*)&big[i]);
		}
		i++;
	}
	return (NULL);
}
