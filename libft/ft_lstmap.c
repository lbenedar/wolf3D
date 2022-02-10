/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <lbenedar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:34:02 by lbenedar          #+#    #+#             */
/*   Updated: 2020/11/11 19:10:19 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*addlist;
	t_list	*newlist;

	if (!lst)
		return (0);
	newlist = 0;
	while (lst)
	{
		addlist = ft_lstnew((*f)(lst->content));
		if (!addlist)
		{
			ft_lstclear(&newlist, del);
			return (0);
		}
		ft_lstadd_back(&newlist, addlist);
		lst = lst->next;
	}
	return (newlist);
}
