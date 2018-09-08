/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 10:00:27 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/31 10:00:28 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_nr_of_words(char const *s, char c)
{
	size_t	ret;
	size_t	i;

	if (*s == '\0')
		return (0);
	ret = 0;
	if (*s != c)
		ret = 1;
	i = 1;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			ret++;
		i++;
	}
	return (ret);
}

static char		*ft_get_next_word(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	l;

	l = 0;
	while (*s && *s != c)
	{
		l++;
		s++;
	}
	return (l);
}

static void		ft_clean_up(char **ret, size_t i)
{
	while (i-- > 0)
		ft_strdel(&ret[i]);
	ft_strdel(ret);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	num_wrds;
	char	**str;

	if (!s)
		return (NULL);
	num_wrds = ft_get_nr_of_words(s, c);
	str = (char **)ft_memalloc(sizeof(char *) * (num_wrds + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < num_wrds)
	{
		s = ft_get_next_word(s, c);
		str[i++] = ft_strsub(s, 0, ft_wordlen(s, c));
		if (str[i - 1] == NULL)
		{
			ft_clean_up(str, i);
			return (NULL);
		}
		s = s + ft_wordlen(s, c);
	}
	str[num_wrds] = 0;
	return (str);
}
