/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:22:42 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/19 08:14:45 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>



int	ft_is_chunk(int position, int size, int chunk_size, t_s *stp)
{
	int	i;

	i = 0;
	while (i * chunk_size < stp->length - size)
		i++;
	if (position < i * chunk_size && position >= (i - 1) * chunk_size)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_s	stacks;

	stacks.sa = NULL;
	stacks.sb = NULL;
	stacks.length = initialize_stack(argc, argv, &stacks);
	if (argc < 2 || stacks.length == -1)
		return (EXIT_FAILURE);
	ft_init_position(&stacks);

	ft_printf("Is in chunk? %d", ft_is_chunk(0, ft_lstsize(stacks.sa), 2, &stacks));
	// if (ft_is_sorted(&stacks))
	// 	return (ft_sanitize(&stacks));
	// else if (ft_lstsize(stacks.sa) == 2)
	// 	ft_swap(&stacks, "sa");
	// else if (ft_lstsize(stacks.sa) == 3)
	// 	ft_sort_3(&stacks);
	// else
	// 	ft_sort(&stacks);


	//ft_printf("Min an der stelle: %d\n",ft_search_min_bottom(&stacks, 4, ft_lstsize(stacks.sa)));
	//ft_put_stack(&stacks);
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
