/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnemangw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 10:48:08 by tnemangw          #+#    #+#             */
/*   Updated: 2018/06/30 16:21:45 by tnemangw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	info_to_stck(int const fd, char **stck)
{
	char	*buffer;
	int		ret;
	char	*temp;

	if (!(buffer = (char *)malloc(sizeof(*buffer) * (BUFF_SIZE + 1))))
		return (-1);
	ret = read(fd, buffer, BUFF_SIZE);
	if (ret > 0)
	{
		buffer[ret] = '\0';
		temp = ft_strjoin(*stck, buffer);
		free(*stck);
		*stck = temp;
	}
	free(buffer);
	return (ret);
}

static void	free_join(char **stck)
{
	char	*tmp;

	tmp = *stck;
	*stck = ft_strjoin(*stck, "\n");
	free(tmp);
}

static void	check(char **stck, char **line, char **endl)
{
	char	*tmp;

	tmp = *stck;
	*line = ft_strsub(*stck, 0, ft_strlen(*stck) - ft_strlen(*endl));
	*stck = ft_strdup(*endl + 1);
	free(tmp);
}

int			get_next_line(int const fd, char **line)
{
	static char	*stck = NULL;
	char		*endl;
	int			ret;

	if ((!stck && (stck = (char *)malloc(sizeof(*stck))) == NULL) || !line
			|| fd < 0 || BUFF_SIZE < 0)
		return (-1);
	endl = ft_strchr(stck, '\n');
	while (endl == NULL)
	{
		ret = info_to_stck(fd, &stck);
		if (ret == 0)
		{
			if (ft_strlen(stck) == 0)
				return (0);
			free_join(&stck);
		}
		if (ret < 0)
			return (-1);
		else
			endl = ft_strchr(stck, '\n');
	}
	check(&stck, line, &endl);
	return (1);
}
