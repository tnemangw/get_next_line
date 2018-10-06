/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 12:45:38 by tnemangw          #+#    #+#             */
/*   Updated: 2018/06/03 15:29:08 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	j;

	j = 0;
	while ((j < n) && (s1[j] != '\0') && (s2[j] != '\0') && (s1[j] == s2[j]))
		j++;
	if (n == j)
		return (0);
	return ((unsigned char)s1[j] - (unsigned char)s2[j]);
}
