/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:22:42 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/24 20:25:46 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	ft_sanitize(&stacks);
	return (EXIT_SUCCESS);
}
