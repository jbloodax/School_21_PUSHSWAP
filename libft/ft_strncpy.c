/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:36:07 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/20 13:26:30 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		over_len;

	i = 0;
	over_len = 0;
	while (i < n)
	{
		if (src[i] && !over_len)
			dest[i] = src[i];
		else
		{
			dest[i] = '\0';
			over_len = 1;
		}
		i++;
	}
	return (dest);
}
