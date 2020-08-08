/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:19:56 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/22 16:13:01 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*line;

	len = 0;
	while (src[len] != '\0')
		len++;
	if (!(line = (char*)malloc((len + 1) * sizeof(*line))))
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		line[i] = src[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
