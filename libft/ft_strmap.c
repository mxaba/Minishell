/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 09:58:03 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/31 09:58:05 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	len;
	unsigned int	i;
	char			*str;

	i = 0;
	str = NULL;
	if (s)
	{
		len = ft_strlen(s);
		str = (char*)malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			return (NULL);
		while (i < len)
		{
			str[i] = (*f)(s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
