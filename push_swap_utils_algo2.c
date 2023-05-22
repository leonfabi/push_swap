/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_algo2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:13:15 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/22 13:40:32 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_is_in_A(t_s *stp, int position)
{
	t_list	*tmpa;
	t_list	*tmpb;

	tmpa = stp->sa;
	while (tmpa)
	{
		if (((t_s_c *)tmpa->content)->position == position)
			return (1);
			tmpa = tmpa->next;
	}
	while (tmpb)
	{
		if (((t_s_c *)tmpb->content)->position == position)
			return (0);
			tmpb = tmpb->next;
	}
	return (-1);
}

void	ft_rotate_pb_min(t_s *stp, int position)
{
	int		i;
	t_list	*tmp;

	tmp = stp->sb;
	i = 0;
	while (tmp)
	{
		if (((t_s_c *)tmp->content)->position == position)
			tmp = NULL;
		else
		{
		tmp = tmp->next;
		i++;
		}
	}
	if (i > ft_lstsize(stp->sb) - i)
	{
		while ((ft_lstsize(stp->sb) - i++))
			ft_rotate(stp,"rrb");
	}
	else 
	{
		while (i--)
			ft_rotate(stp,"rb");
	}
}
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
		ft_push_to_b_low_cost(stp, 10, ft_lstsize(stp->sa));
		// if (((t_s_c *)stp->sb->content)->position <= count++)
		// 	ft_rotate(stp, "rb");
	}

	// while (stp->sa)
	// {
	// 	if (((t_s_c *)stp->sa->content)->position <= threshold + count)
	// 	{
	// 		ft_push(stp, "pb");
	// 		if (((t_s_c *)stp->sb->content)->position <= count++)
	// 			ft_rotate(stp, "rb");
	// 	}
	// 	else if (ft_lstsize(stp->sa) > 2)
	// 		ft_rotate(stp, "ra");
	// }
	while (length--)
	{
		ft_rotate_pb_min(stp, length);
		ft_push(stp, "pa");
	}
}
