/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:30:41 by tnemangw          #+#    #+#             */
/*   Updated: 2018/06/10 11:47:58 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long n)
{
	int i;

	i = 1;
	if (n < 0)
		i++;
	n /= 10;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		i;
	long	k;

	k = (long)n;
	i = len(k);
	if (!(ret = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	ret[i--] = '\0';
	if (k < 0)
	{
		ret[0] = '-';
		k = -k;
	}
	ret[i--] = (k % 10) + '0';
	k /= 10;
	while (k)
	{
		ret[i--] = (k % 10) + '0';
		k /= 10;
	}
	return (ret);
}
