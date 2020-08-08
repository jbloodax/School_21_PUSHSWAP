/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:57:12 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/19 17:58:28 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*last_ch;

	last_ch = (char*)str + ft_strlen(str);
	while (*last_ch != ch)
	{
		if (last_ch == str)
		{
			return (NULL);
		}
		last_ch--;
	}
	return (last_ch);
}
