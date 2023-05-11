/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:07:27 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/11 20:30:53 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	// if (lst != NULL)
	// {
	// 	if (*lst != NULL)
	// 		new->next = *lst;
	// 	*lst = new;
	// }
	new->next = *lst;
	*lst = new;
}
