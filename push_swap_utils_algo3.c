/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_algo3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:59:26 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/23 14:28:51 by fkrug            ###   ########.fr       */
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

// int		ft_find_final_p_in_a(t_s *stp, int p)
// {
// 	t_list	*tmp;
// 	t_list	*prev;
// 	int		cond1;
// 	int		cond2;
// 	int		i;

// 	tmp = stp->sa;
// 	prev = ft_lstlast(tmp);
// 	cond1 = 0;
// 	cond2 = 0;
// 	i = 0;
// 	while (tmp)
// 	{
// 		if(p > ((t_s_c*)tmp->c)->p)
// 			cond1 = 1;
// 		if(p < ((t_s_c*)prev->c)->p)
// 			cond2 = 1;
// 		if (cond1 && cond2)
// 			return (i);
// 		i++;
// 		prev = tmp;
		
// 	}
// }

void	ft_push_to_a(t_s *stp)
{
	
}
