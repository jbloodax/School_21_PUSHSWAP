/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:05:43 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/22 19:34:17 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		m;
	int		n;
	int		t;

	m = 0;
	n = 0;
	if (!s || !(split = malloc(sizeof(char *) * (ft_count_words(s, c) + 1))))
		return (NULL);
	while (s[m] != '\0')
	{
		while (s[m] == c && s[m] != '\0')
			m++;
		if (s[m] != '\0')
		{
			t = 0;
			if (!(split[n] = malloc(ft_len_word(s + m, c) + 1)))
				return (ft_freestr(split));
			while (s[m] != c && s[m] != '\0')
				split[n][t++] = s[m++];
			split[n++][t] = '\0';
		}
	}
	split[n] = NULL;
	return (split);
}
