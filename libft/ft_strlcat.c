/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 11:14:10 by tnemangw          #+#    #+#             */
/*   Updated: 2018/06/11 15:48:54 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*k;
	char	*p;
	size_t	j;

	k = (char *)ft_memchr(dst, '\0', size);
	if (k == NULL)
		return (size + ft_strlen(src));
	p = (char *)src;
	j = (size_t)(k - dst) + ft_strlen(p);
	while ((size_t)(k - dst) < size - 1 && *p != '\0')
	{
		*k = *p;
		k++;
		p++;
	}
	*k = '\0';
	return (j);
}
