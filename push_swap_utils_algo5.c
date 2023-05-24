/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_algo5.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:26:58 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/24 21:27:14 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_s *stp)
{
	int	old;

	old = 0;
	while (ft_lstsize(stp->sa) > 3)
		old = ft_push_to_b(stp, old, stp->length);
	ft_sort_3(stp);
	while (ft_lstsize(stp->sb))
		ft_push_to_a(stp);
	if (ft_rotate_top(stp, 0, "A", 0) < ft_rotate_top(stp, 0, "A", 1))
		ft_do_move(stp, ft_rotate_top(stp, 0, "A", 0), "ra");
	else
		ft_do_move(stp, ft_rotate_top(stp, 0, "A", 1), "rra");
}
