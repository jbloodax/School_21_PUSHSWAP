/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:27:08 by jbloodax          #+#    #+#             */
/*   Updated: 2019/09/22 19:42:10 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_clear(t_list *root)
{
	t_list *temp;

	while (root)
	{
		temp = root->next;
		free(root);
		root = temp;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*fresh;

	if (!lst || !f || !(list = f(lst)))
		return (NULL);
	fresh = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = f(lst)))
		{
			ft_clear(fresh);
			return (NULL);
		}
		list = list->next;
	}
	return (fresh);
}
