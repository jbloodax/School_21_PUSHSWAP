/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:54:36 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/18 13:44:01 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*sub;
	const unsigned char	*pos;
	size_t				i;
	unsigned char		ch;

	sub = (unsigned char*)dest;
	pos = (unsigned char*)src;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (pos[i] == ch)
		{
			sub[i] = pos[i];
			return (&dest[i + 1]);
		}
		else
			sub[i] = pos[i];
		i++;
	}
	return (NULL);
}
