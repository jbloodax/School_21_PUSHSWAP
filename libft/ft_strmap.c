/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:01:56 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/13 17:02:50 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*new;
	int		i;

	str = (char*)s;
	if (str && f)
	{
		i = 0;
		if (!(new = ft_memalloc((size_t)ft_strlen((char*)s) + 1)))
			return (NULL);
		while (str[i])
		{
			new[i] = (*f)(str[i]);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (0);
}
