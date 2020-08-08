/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:42:10 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/14 15:43:02 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *d, int c, size_t n)
{
	unsigned char	*dest;

	dest = (unsigned char*)d;
	while (n-- > 0)
		*(dest++) = (unsigned char)c;
	return (d);
}
