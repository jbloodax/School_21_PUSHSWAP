/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:36:14 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/20 13:25:30 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			k;

	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	k = 0;
	if (n == 0)
		return (0);
	while (s1[k] == s2[k] && s1[k] != '\0' && s1[k] != '\0' && k < n - 1)
		k++;
	return (s1[k] - s2[k]);
}
