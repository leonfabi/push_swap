/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:47:38 by fkrug             #+#    #+#             */
/*   Updated: 2023/03/28 18:31:34 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*add;
	t_list	*head;

	head = NULL;
	if (!lst | !f | !del)
		return (NULL);
	while (lst)
	{
		add = ft_lstnew((*f)(lst->content));
		if (!add)
		{
			ft_lstclear(&head, *del);
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&head, add);
		lst = lst->next;
	}
	return (head);
}
