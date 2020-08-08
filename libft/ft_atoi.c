/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <jbloodax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:12:14 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/21 20:36:32 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long int	nbr;
	long long int	temp;
	int				minus;
	int				i;

	nbr = 0;
	minus = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
					|| str[i] == '\r' || str[i] == '\v' || str[i] == '\t')
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	temp = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = temp * 10 + (str[i] - '0');
		if ((minus > 0 && nbr < temp) || (minus < 0 && nbr < temp))
			return (minus > 0 ? -1 : 0);
		temp = nbr;
		i++;
	}
	return (nbr * minus);
}
