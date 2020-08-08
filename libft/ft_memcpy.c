/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:23:46 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/20 13:53:46 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*sub;
	const unsigned char	*pos;

	if (n == 0 || dest == src)
		return (dest);
	sub = (unsigned char*)dest;
	pos = (unsigned char*)src;
	while (n-- > 0)
		*(sub++) = *(pos++);
	return (dest);
}
