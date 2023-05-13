/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_operations.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:02:58 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/13 12:54:22 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_s *stp, char *operation)
{
	t_list	*tmp;

	tmp = NULL;
	if (!ft_strncmp(operation, "sa", 3))
	{
		if (ft_lstsize(stp->sa) < 2)
			return;
		tmp = stp->sa;
		stp->sa = stp->sa->next;
		tmp->next = stp->sa->next;
		stp->sa->next = tmp;
		ft_putendl_fd(operation,STDOUT_FILENO);
	}
	else if (!ft_strncmp(operation, "sb", 3))
	{
		ft_printf("operation sb");
	}
}

void	ft_put_stack(t_s *stp)
{
	t_list	*tmp;

	tmp = stp->sa;
	ft_printf("Print stack a:\n______\n");
	while (tmp)
	{
		ft_printf("%d\n_____\n",((t_s_c *)tmp->content)->number);
		tmp = tmp->next;
	}
	ft_printf("END\n");
}