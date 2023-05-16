/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_algo2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:13:15 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/16 12:53:22 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_s *stp)
{
	int	count;
	int	length;
	int	threshold;

	count = 0;
	length = ft_lstsize(stp->sa);
	threshold = length/3;
	while (stp->sa)
	{
		if (((t_s_c *)stp->sa->content)->position <= threshold + count)
		{
			ft_push(stp, "pb");
			if (((t_s_c *)stp->sb->content)->position <= count++)
				ft_rotate(stp, "rb");
		}
		else if (ft_lstsize(stp->sa) > 2)
			ft_rotate(stp, "ra");
	}
	while (length--)
	{
		while (((t_s_c *)stp->sb->content)->position != length)
		{
			ft_rotate(stp, "rb");
		}
		ft_push(stp, "pa");
	}
}
