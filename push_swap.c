/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:22:42 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/17 16:05:49 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	initialize_stack(int argc, char **argv, t_s *stp)
{
	int		i;
	int		length;
	char	**tmp;

	i = 0;
	length = 0;
	while (argc-- > 1)
	{
		tmp = ft_split(argv[argc], ' ');
		i = 0;
		while (tmp[i])
		{
			if (ft_error(stp, tmp, !is_str_valid(tmp[i])))
				return (-1);
			ft_lstadd_front(&(stp->sa), ft_lstnew(ft_cnew(ft_atoi(tmp[i]), 0)));
			length++;
			i++;
		}
		if (ft_error(stp, tmp, ft_list_double(stp->sa)))
			return (-1);
		else
			ft_free_2d(tmp);
	}
	return (length);
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


	if (ft_is_sorted(&stacks))
		return (ft_sanitize(&stacks));
	else if (ft_lstsize(stacks.sa) == 2)
		ft_swap(&stacks, "sa");
	else if (ft_lstsize(stacks.sa) == 3)
		ft_sort_3(&stacks);
	else
		ft_sort(&stacks);


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
