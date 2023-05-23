/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:22:42 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/23 14:29:27 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_call_sort_algo(t_s *stp)
{
	if (ft_lstsize(stp->sa) == 2)
		ft_swap(stp, "sa");
	else if (ft_lstsize(stp->sa) == 3)
		ft_sort_3(stp);
	else
		ft_sort(stp);
}

int	main(int argc, char **argv)
{
	t_s	stacks;

	stacks.sa = NULL;
	stacks.sb = NULL;
	stacks.length = initialize_stack(argc, argv, &stacks);
	if (argc < 2 || stacks.length == -1)
		return (EXIT_FAILURE);
	ft_init_p(&stacks);


	if (ft_is_sorted(&stacks))
		return (ft_sanitize(&stacks));
	else if (ft_lstsize(stacks.sa) == 2)
		ft_swap(&stacks, "sa");
	else if (ft_lstsize(stacks.sa) == 3)
		ft_sort_3(&stacks);
	else
		ft_sort(&stacks);



	//Example from pdf
	// ft_put_stack(&stacks);
	// ft_swap(&stacks,"sa");
	// ft_put_stack(&stacks);
	// ft_push(&stacks, "pb");
	// ft_push(&stacks, "pb");
	// ft_push(&stacks, "pb");
	// ft_put_stack(&stacks);
	// ft_rotate(&stacks,"rr");
	// ft_put_stack(&stacks);
	// ft_rotate(&stacks,"ra");
	// ft_put_stack(&stacks);
	// ft_swap(&stacks,"sa");
	// ft_put_stack(&stacks);
	// ft_push(&stacks, "pa");
	// ft_push(&stacks, "pa");
	// ft_push(&stacks, "pa");
	// ft_put_stack(&stacks);
	//ft_printf("\nis sorted %d\n", ft_is_sorted(&stacks));void	ft_sort_3(t_s *stp)
	//ft_put_stack(&stacks);
	//ft_sort_3(&stacks);
	//ft_put_stack(&stacks);
	ft_sanitize(&stacks);
	return (EXIT_SUCCESS);
}
