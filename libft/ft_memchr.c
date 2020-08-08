/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:55:58 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/14 18:17:30 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *array, int c, size_t n)
{
	unsigned char	*search;
	size_t			i;

	i = 0;
	search = (unsigned char*)array;
	while (++i <= n)
	{
		if (*(search++) == (unsigned char)c)
			return ((void *)--search);
	}
	return (NULL);
}
