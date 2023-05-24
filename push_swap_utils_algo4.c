/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_algo4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:41:21 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/24 21:48:19 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_move(t_s *stp, int a, char *ao)
{
	while (a--)
		ft_rotate(stp, ao);
}

void	ft_do_double_move(t_s *stp, int a, int b, char *ao)
{
	int	double_rotate;
	int	single_rotate;

	double_rotate = 0;
	single_rotate = 0;
	double_rotate = ft_rarb_sum(a, b, 1);
	single_rotate = ft_rarb_sum(a, b, 0) - double_rotate;
	while (double_rotate--)
		ft_rotate(stp, ao);
	if (a > b && !ft_strncmp(ao, "rr", 3))
		ft_do_move(stp, single_rotate, "ra");
	if (b > a && !ft_strncmp(ao, "rr", 3))
		ft_do_move(stp, single_rotate, "rb");
	if (a > b && !ft_strncmp(ao, "rrr", 4))
		ft_do_move(stp, single_rotate, "rra");
	if (b > a && !ft_strncmp(ao, "rrr", 4))
		ft_do_move(stp, single_rotate, "rrb");
}

void	ft_which_move(t_s *stp, int p, int move)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;

	ra = ft_find_final_p_in_a(stp, p);
	rra = ft_lstsize(stp->sa) - ra;
	rb = ft_rotate_top(stp, p, "B", 0);
	rrb = ft_rotate_top(stp, p, "B", 1);
	if (move == rra + rb)
	{
		ft_do_move(stp, rra, "rra");
		ft_do_move(stp, rb, "rb");
	}
	else if (move == rrb + ra)
	{
		ft_do_move(stp, rrb, "rrb");
		ft_do_move(stp, ra, "ra");
	}
	else if (move == ft_rarb_sum(ra, rb, 0))
		ft_do_double_move(stp, ra, rb, "rr");
	else if (move == ft_rarb_sum(rra, rrb, 0))
		ft_do_double_move(stp, rra, rrb, "rrr");
}

int	ft_calc_min_moves(t_s *stp, int p)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	sum;

	ra = ft_find_final_p_in_a(stp, p);
	rra = ft_lstsize(stp->sa) - ra;
	rb = ft_rotate_top(stp, p, "B", 0);
	rrb = ft_rotate_top(stp, p, "B", 1);
	sum = rra + rb;
	if (sum > rrb + ra)
		sum = rrb + ra;
	if (sum > ft_rarb_sum(ra, rb, 0))
		sum = ft_rarb_sum(ra, rb, 0);
	if (sum > ft_rarb_sum(rra, rrb, 0))
		sum = ft_rarb_sum(rra, rrb, 0);
	return (sum);
}

int	ft_push_to_a(t_s *stp)
{
	int		min;
	int		move;
	t_list	*tmp;
	int		p;

	p = 0;
	min = stp->length;
	move = 0;
	tmp = stp->sb;
	while (tmp)
	{
		move = ft_calc_min_moves(stp, ((t_s_c *)tmp->c)->p);
		if (move < min)
		{
			p = ((t_s_c *)tmp->c)->p;
			min = move;
		}
		tmp = tmp->next;
	}
	ft_which_move(stp, p, min);
	ft_push(stp, "pa");
	return (p);
}
