/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 11:27:51 by tnemangw          #+#    #+#             */
/*   Updated: 2018/06/15 16:18:38 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	no_words(char *s, char c)
{
	int		num;
	int		i;

	num = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i - 1] == c || !s[i - 1]))
			num++;
		i++;
	}
	return (num);
}

static char	*add_num(char *s, char c)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	res = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (s[i] && s[i] != c)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;

	if (!s || !s)
		return (NULL);
	i = 0;
	j = 0;
	if (!(res = (char **)malloc(sizeof(char *) * no_words((char *)s, c) + 1)))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || !s[i - 1]))
			res[j++] = add_num((char *)s + i, c);
		i++;
	}
	res[j] = NULL;
	return (res);
}
