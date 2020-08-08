/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:04:46 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/13 18:58:55 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char *first;
	char *second;

	first = (char*)s1;
	second = (char*)s2;
	if (first && second)
	{
		if (ft_strncmp(first, second, n) == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
