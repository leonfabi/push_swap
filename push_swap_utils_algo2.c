/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_algo2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:13:15 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/17 16:07:29 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_search_min_bottom(t_s *stp, int srch_len, int size)
{
	t_list	*tmp;
	int		min;
	int		i;
	int		count;

	count = 0;
	tmp = stp->sa;
	i = -1 * size;
	min = size;
	while (size--)
	{
		tmp = tmp -> next;
		if (size < srch_len + 1 && size > 0 && ((t_s_c *)tmp->content)->position < min)
		{
			min = ((t_s_c *)stp->sa->content)->position;
			i = size;
		}
	}
	return (i);
}

int	ft_search_min_top(t_s *stp, int srch_len, int size)
{
	t_list	*tmp;
	int		min;
	int		i;
	int		count;

	count = 0;
	tmp = stp->sa;
	i = 0;
	min = ((t_s_c *)stp->sa->content)->position;
	while (count < size - 1)
	{
		tmp = tmp -> next;
		count++;
		if (((t_s_c *)tmp->content)->position < min && count < srch_len)
		{
			min = ((t_s_c *)tmp->content)->position;
			i = count;
		}
	}
	return (i);
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
void	ft_push_to_b_low_cost(t_s *stp, int srch_len, int size)
{
	int	ra;
	int	rra;
	
	ra = ft_search_min_top(stp, srch_len, size);
	rra = ft_search_min_bottom(stp, srch_len, size);
	if (ra >= rra)
	{
		while (ra--)
			ft_rotate(stp, "ra");
	}
	else
	{
		while (rra--)
			ft_rotate(stp, "rra");
	}
	ft_push(stp,"pb");
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
		ft_push_to_b_low_cost(stp, 5, ft_lstsize(stp->sa));
		if (((t_s_c *)stp->sb->content)->position <= count++)
			ft_rotate(stp, "rb");
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
