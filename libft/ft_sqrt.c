/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:14:31 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/22 14:02:16 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int sqrt;
	int output;

	output = 1;
	sqrt = 0;
	while (output <= nb / 2)
	{
		sqrt = output * output;
		if (sqrt == nb)
			return (output);
		output++;
	}
	return (0);
}
