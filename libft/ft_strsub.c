/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 10:00:55 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/31 10:00:56 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = NULL;
	if (s)
	{
		str = (char*)malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			return (NULL);
		while (i < len)
		{
			str[i] = s[start];
			start++;
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
