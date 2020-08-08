/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:37:51 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/22 16:08:54 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **link, void (*del)(void*, size_t))
{
	if (!link || !del)
		return ;
	del((*link)->content, (*link)->content_size);
	free(*link);
	*link = NULL;
}
