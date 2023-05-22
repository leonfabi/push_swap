/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_algo2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:13:15 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/22 17:45:04 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_in_A(t_s *stp, int position)
{
	t_list	*tmpa;
	t_list	*tmpb;

	tmpa = stp->sa;
	tmpb = stp->sb;
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

int	ft_is_all_B(t_s *stp, int position)
{
	int	i = 0;

	while (i <= position)
	{
		if (ft_is_in_A(stp, i))
			return (1);
		i++;
	}
	return (0);
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

int	ft_push_to_b(t_s *stp, int old, int length)
{
	t_list	*tmp;
	static int	i = 0;
	int	a;
	int	b;
	int	c;

	a = old;
	b = (length - a - 1) / 3 + (length - a - 1) % 3 + a;
	c = 2 * (length - a - 1) / 3 + 2 * (length - a - 1) % 3 + a;
	tmp = stp->sa;
	//while (ft_lstsize(tmp) > (length-old - 1)/3 + (length-old - 1)%3)
	while (ft_is_all_B(stp, c))
	{
		//ft_printf("Position:%d\t|%d|%d|%d|\tEndbedingung:%d\tListelaenge:%d\n",((t_s_c *)tmp->content)->position,a,b,c,(length-old - 1)/3 + (length-old - 1)%3,ft_lstsize(tmp));
		if (((t_s_c *)tmp->content)->position >= a && b > ((t_s_c *)tmp->content)->position)
		{
			ft_push(stp, "pb");
			if (c < ((t_s_c *)tmp->next->content)->position)
				ft_rotate(stp, "rr");
			else
				ft_rotate(stp, "rb");
		}
		else if (((t_s_c *)tmp->content)->position >= b && c >= ((t_s_c *)tmp->content)->position)
			ft_push(stp, "pb");
		else
			ft_rotate(stp, "ra");
		tmp = stp->sa;
	}
	return ((length-old)/3*2+old);
}

void	ft_sort(t_s *stp)
{
	int	old;
	int	length;

	old = 0;
	length = stp->length;
	while (old < length - 3)
	{
		old = ft_push_to_b(stp, old, length);
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
