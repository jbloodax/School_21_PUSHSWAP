/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:03:12 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/22 14:14:37 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char const *str, char c)
{
	int		j;
	int		count;

	j = 0;
	count = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[j] != '\0')
	{
		if (str[j] == c && str[j + 1] != c && str[j + 1] != '\0')
			count++;
		j++;
	}
	if (str[0] != c)
		count++;
	return (count);
}
