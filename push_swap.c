/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:22:42 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/12 18:15:17 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	initialize_stack(int argc, char **argv, t_s *stack_ptr)
{
	int		count;
	char	**tmp;

	count = 0;
	while (argc-- > 1)
	{
		tmp = ft_split(argv[argc], ' ');
		count = 0;
		while (tmp[count])
		{
			if (!is_str_valid(tmp[count]))
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				return (0);
			}
			ft_lstadd_front(&(stack_ptr->sa), ft_lstnew(ft_contentnew(ft_atoi(tmp[count]),0)));
			// printf("Memory address sa: %p\n", &stack_ptr->sa);
			// printf("Memory address content: %p\n", &stack_ptr->sa->content);
			// printf("Function call add front\nsizeof t_s_c: %d\nlist: %d\n",(int)sizeof(t_s_c),(int)sizeof(t_list));
			count++;
		}
		count = 0;
		while (tmp[count])
			free(tmp[count++]);
		free(tmp);
		//doppelte zahlen
	}
	// free(stack_ptr->sa->content);
	// free(stack_ptr->sa);
	return 0;
}

int	main(int argc, char **argv)
{
	t_s	stacks;

	stacks.sa = NULL;
	stacks.sb = NULL;
	if (argc < 2)
		return (EXIT_FAILURE);
	initialize_stack(argc, argv, &stacks);
	/*while (stacks.sa)
	{
		ft_printf("________\n%d\n",((t_s_c *)stacks.sa->content)->number);
		stacks.sa = stacks.sa->next;
	}*/
	// printf("Memory address sa: %p\n", (void *)&stacks.sa);
	// printf("Memory address content: %p\n", (void *)&(stacks.sa->content));
	//free((stacks.sa->content));
	//free(stacks.sa);
	ft_sanitize(&stacks);
	return (EXIT_SUCCESS);
}
