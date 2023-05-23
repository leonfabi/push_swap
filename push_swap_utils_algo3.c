/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_algo3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:59:26 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/23 20:28:26 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_max(t_s *stp, char *stack, int max)
{
	t_list	*tmp;
	int		p;

	if (max == 1)
		p = 0;
	else
		p = stp->length - 1;
	if (!ft_strncmp(stack, "A", 2))
		tmp = stp->sa;
	else if (!ft_strncmp(stack, "B", 2))
		tmp = stp->sb;
	while (tmp)
	{
		if (p < ((t_s_c*)tmp->c)->p && max == 1)
			p = ((t_s_c*)tmp->c)->p;
		if (p > ((t_s_c*)tmp->c)->p && max == 0)
			p = ((t_s_c*)tmp->c)->p;
		tmp = tmp->next;
	}
	return (p);
}
//find element in b with smallest amount of moves to push to a
//determine where in A it has to go
//determine how B has to be modified and how A has to be modified
int		ft_p_in_a_mm(t_s *stp, int max, int value)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = stp->sa;
	while (((t_s_c*)tmp->c)->p != value)
	{
		i++;
		tmp = tmp->next;
	}
	if (max)
		return (i + 1);
	else
		return (i);
}

int		ft_find_final_p_in_a(t_s *stp, int p)
{
	t_list	*tmp;
	t_list	*prev;
	int		i;

	tmp = stp->sa;
	prev = ft_lstlast(tmp);
	i = 0;
	if (ft_stack_max(stp, "A", 1) < p)
		return (ft_p_in_a_mm(stp, 1, ft_stack_max(stp, "A", 1)));
	if (ft_stack_max(stp, "A", 0) > p)
		return (ft_p_in_a_mm(stp, 0, ft_stack_max(stp, "A", 0)));
	while (i < ft_lstsize(stp->sa))
	{
		if(p < ((t_s_c*)tmp->c)->p && p > ((t_s_c*)prev->c)->p)
			return (i);
		i++;
		prev = tmp;
		if (tmp->next == NULL)
			tmp = stp->sa;
		else
			tmp = tmp->next;
	}
	return (-1);
}

int	ft_rotate_top(t_s *stp, int p, char *stack, int rev)
{
	t_list	*tmp;
	int		i;
	int		length;

	i = 0;
	if (!ft_strncmp(stack, "A", 2))
		tmp = stp->sa;
	else if (!ft_strncmp(stack, "B", 2))
		tmp = stp->sb;
	length = ft_lstsize(tmp);
	while (tmp && p != ((t_s_c*)tmp->c)->p)
	{
		i++;
		tmp = tmp->next;
	}
	if (rev)
		return (length - i);
	else
		return (i);
}
int	ft_rarb_sum(int ra, int rb)
{
	int	sum;

	sum = 0;
	while (ra && rb)
	{
		sum++;
		ra--;
		rb--;
	}
	sum = sum + ra + rb;
	return (sum);
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
	if (sum > ft_rarb_sum(ra, rb))
		sum = ft_rarb_sum(ra, rb);
	if (sum > ft_rarb_sum(rra, rrb))
		sum = ft_rarb_sum(rra, rrb);
	return (sum);
}

void	ft_push_to_a(t_s *stp)
{
	int		min;
	int		move;
	t_list	*tmp;

	min = stp->length;
	move = 0;
	tmp = stp->sb;
	while (tmp)
	{
		move = ft_calc_min_moves(stp,((t_s_c*)tmp->c)->p);
		if (move < min)
			min = move;
		tmp = tmp->next;
	}
}
