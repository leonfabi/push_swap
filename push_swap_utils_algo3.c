/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_algo3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:59:26 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/23 09:00:02 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_max(t_s *stp, char *stack, int max)
{
	t_list	*tmp;
	int		position;

	if (max == 1)
		position = 0;
	else
		position = stp->length - 1;
	if (!ft_strncmp(stack, "A", 2))
		tmp = stp->sa;
	else if (!ft_strncmp(stack, "B", 2))
		tmp = stp->sb;
	while (tmp)
	{
		if (position < ((t_s_c*)tmp->content)->position && max == 1)
			position = ((t_s_c*)tmp->content)->position;
		if (position > ((t_s_c*)tmp->content)->position && max == 0)
			position = ((t_s_c*)tmp->content)->position;
		tmp = tmp->next;
	}
	return (position);
}
