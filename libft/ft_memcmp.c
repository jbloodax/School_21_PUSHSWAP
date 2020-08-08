/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:15:54 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/18 15:36:33 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*arr1;
	unsigned char	*arr2;
	size_t			i;

	if (n == 0)
		return (0);
	arr1 = (unsigned char*)str1;
	arr2 = (unsigned char*)str2;
	i = 0;
	while (*arr1 == *arr2 && ++i < n)
	{
		arr1++;
		arr2++;
	}
	return (*arr1 - *arr2);
}
