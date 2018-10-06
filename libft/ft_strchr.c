/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 12:23:38 by tnemangw          #+#    #+#             */
/*   Updated: 2018/06/06 15:55:37 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		k;

	k = 0;
	while (s[k])
	{
		if (s[k] == c)
			return ((char *)s + k);
		k++;
	}
	if (!c && s[k] == '\0')
		return ((char *)s + k);
	return (NULL);
}
