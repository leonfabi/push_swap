/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:37:25 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/25 15:38:30 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_stack(t_s *stp)
{
	t_list	*tmp;

	tmp = stp->sa;
	ft_printf("Print stack a:\n______\n");
	while (tmp)
	{
		ft_printf("%d\t%d\n_____\n", ((t_s_c *)tmp->c)->number, ((t_s_c *)tmp->c)->p);
		tmp = tmp->next;
	}
	ft_printf("END\n");
	tmp = stp->sb;
	ft_printf("Print stack b:\n______\n");
	while (tmp)
	{
		ft_printf("%d\t%d\n_____\n", ((t_s_c *)tmp->c)->number, ((t_s_c *)tmp->c)->p);
		tmp = tmp->next;
	}
	ft_printf("END\n");
}
