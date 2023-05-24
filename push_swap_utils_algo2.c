/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_algo2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:00:39 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/24 20:23:48 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_in_A(t_s *stp, int p)
{
	t_list	*tmpa;
	t_list	*tmpb;

	tmpa = stp->sa;
	tmpb = stp->sb;
	while (tmpa)
	{
		if (((t_s_c *)tmpa->c)->p == p)
			return (1);
		tmpa = tmpa->next;
	}
	while (tmpb)
	{
		if (((t_s_c *)tmpb->c)->p == p)
			return (0);
		tmpb = tmpb->next;
	}
	return (0);
}

int	ft_is_all_B(t_s *stp, int p)
{
	int	i = 0;

	while (i <= p)
	{
		if (ft_is_in_A(stp, i))
			return (1);
		i++;
	}
	return (0);
}

void	ft_rotate_pb_min(t_s *stp, int p)
{
	int		i;
	t_list	*tmp;

	tmp = stp->sb;
	i = 0;
	while (tmp)
	{
		if (((t_s_c *)tmp->c)->p == p)
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
void	ft_make_move_to_b(t_s *stp, int a, int b, int c)
{
	t_list	*tmp;
	int		rr;

	tmp = stp->sa;
	rr = 0;
	if (((t_s_c *)tmp->c)->p >= a && b > ((t_s_c *)tmp->c)->p)
	{
		if (tmp->next != NULL && c < ((t_s_c *)tmp->next->c)->p)
			rr = 1;
		ft_push(stp, "pb");
		if (rr)
			ft_rotate(stp, "rr");
		else
			ft_rotate(stp, "rb");
	}
	else if (((t_s_c *)tmp->c)->p >= b && c >= ((t_s_c *)tmp->c)->p)
		ft_push(stp, "pb");
	else
		ft_rotate(stp, "ra");
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
	while (ft_is_all_B(stp, c) && ft_lstsize(tmp) > 3)
	{
		//ft_printf("p:%d\t|%d|%d|%d|\tEndbedingung:%d\tListelaenge:%d\n",((t_s_c *)tmp->c)->p,a,b,c,(length-old - 1)/7 + (length-old - 1)%3,ft_lstsize(tmp));
		ft_make_move_to_b(stp, a, b, c);
		tmp = stp->sa;
	}
	return ((length-a)/3*2+a);
}


void	ft_sort(t_s *stp)
{
	int	old;

	old = 0;
	while(ft_lstsize(stp->sa) > 3)
		old = ft_push_to_b(stp, old, stp->length);
	ft_sort_3(stp);
	while (ft_lstsize(stp->sb))
		ft_push_to_a(stp);
	if (ft_rotate_top(stp, 0, "A", 0) < ft_rotate_top(stp, 0, "A", 1))
		ft_do_move(stp, ft_rotate_top(stp, 0, "A", 0), "ra");
	else
		ft_do_move(stp, ft_rotate_top(stp, 0, "A", 1), "rra");
}
