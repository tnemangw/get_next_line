/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:02:11 by tnemangw          #+#    #+#             */
/*   Updated: 2018/06/03 14:49:24 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *haystack, int c)
{
	int len;
	int	j;

	len = ft_strlen(haystack) + 1;
	j = len - 1;
	while (j >= 0)
	{
		if (haystack[j] == c)
			return ((char *)(haystack + j));
		j--;
	}
	return (NULL);
}
