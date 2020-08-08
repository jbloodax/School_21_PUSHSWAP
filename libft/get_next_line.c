/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:33:35 by jbloodax          #+#    #+#             */
/*   Updated: 2019/11/08 19:35:32 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_check_gnl_line(char **rest, char **line)
{
	char	*temp;
	char	*use_rest;

	use_rest = *rest;
	temp = ft_strchr(*rest, '\n');
	if (!temp)
		return (0);
	*temp = '\0';
	*line = ft_strdup(*rest);
	if (*(temp + 1))
		*rest = ft_strdup(temp + 1);
	else
		*rest = NULL;
	free(use_rest);
	return (1);
}

static int		ft_read_gnl_file(int fd, char *buff, char **rest, char **line)
{
	char	*temp_rest;
	int		readsize;

	while ((readsize = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[readsize] = '\0';
		if (*rest)
		{
			temp_rest = *rest;
			*rest = ft_strjoin(temp_rest, buff);
			free(temp_rest);
		}
		else
			*rest = ft_strdup(buff);
		if (ft_check_gnl_line(rest, line))
			break ;
	}
	if (readsize == 0 && *rest)
	{
		*line = ft_strdup(*rest);
		free(*rest);
		*rest = NULL;
		return (1);
	}
	return (readsize > 0 ? 1 : readsize);
}

int				get_next_line(const int fd, char **line)
{
	char		*buff;
	static char	*rest[FD_MAX + 1];
	int			readsize;

	if (line == NULL || fd < 0 || BUFF_SIZE <= 0 || fd > FD_MAX)
		return (-1);
	if (rest[fd])
		if (ft_check_gnl_line(&rest[fd], line))
			return (1);
	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	readsize = ft_read_gnl_file(fd, buff, &rest[fd], line);
	free(buff);
	if (readsize < 0)
		return (-1);
	else if (readsize == 0 && !rest[fd])
	{
		*line = NULL;
		return (0);
	}
	else
		return (1);
}
