/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_operations2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:47:30 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/19 09:04:35 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_shift_up(t_list **list)
{
	t_list	*last;

	last = ft_lstlast(*list);
	last->next = *list;
	*list = (*list)->next;
	last->next->next = NULL;
}

void	ft_shift_down(t_list **list)
{
	t_list	*sec_to_last;

	sec_to_last = *list;
	while (sec_to_last->next->next)
		sec_to_last = sec_to_last->next;
	sec_to_last->next->next = *list;
	*list = sec_to_last->next;
	sec_to_last->next = NULL;
}

void	ft_rotate(t_s *stp, char *operation)
{
	if (!ft_strncmp(operation, "ra", 3) || !ft_strncmp(operation, "rr", 3))
		ft_shift_up(&(stp->sa));
	if (!ft_strncmp(operation, "rb", 3) || !ft_strncmp(operation, "rr", 3))
		ft_shift_up(&(stp->sb));
	if (!ft_strncmp(operation, "rra", 3) || !ft_strncmp(operation, "rrr", 3))
		ft_shift_down(&(stp->sa));
	if (!ft_strncmp(operation, "rrb", 3) || !ft_strncmp(operation, "rrr", 3))
		ft_shift_down(&(stp->sb));
	ft_putendl_fd(operation, STDOUT_FILENO);
}
