/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 10:00:42 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/31 10:00:48 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		len;
	char	*big2;

	big2 = (char*)big;
	i = 0;
	len = 0;
	while (little[len] != '\0')
		len++;
	if (len == 0)
		return (big2);
	while (big2[i] != '\0')
	{
		j = 0;
		while (little[j] == big2[i + j])
		{
			if (little[j + 1] == '\0')
				return (big2 + i);
			j++;
		}
		i++;
	}
	return (0);
}
