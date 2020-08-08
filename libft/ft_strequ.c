/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:04:35 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/14 19:30:25 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	char *first;
	char *second;

	first = (char*)s1;
	second = (char*)s2;
	if (first && second)
	{
		if (ft_strcmp(first, second) == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
