/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:15:20 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/18 12:11:10 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int n;
	int m;

	n = 0;
	while (dest[n] != '\0')
		n++;
	m = 0;
	while (src[m] != '\0')
	{
		dest[n + m] = src[m];
		m++;
	}
	dest[n + m] = '\0';
	return (dest);
}
