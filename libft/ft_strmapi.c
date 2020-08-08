/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:02:07 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/13 18:26:08 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*new;
	unsigned int	i;

	str = (char*)s;
	if (str && f)
	{
		i = 0;
		if (!(new = ft_memalloc((size_t)ft_strlen((char*)s) + 1)))
			return (NULL);
		while (str[i])
		{
			new[i] = (*f)(i, str[i]);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (0);
}
