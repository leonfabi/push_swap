/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:22:42 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/12 14:59:12 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_stack(int argc, char **argv, t_s *state)
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
			ft_lstadd_front(&(state->sa), ft_lstnew(ft_contentnew(ft_atoi(tmp[count]),0)));
			count++;
		}
		//doppelte zahlen
	}
	// ft_printf("Stack: %d",((t_s_c *)state.sa->content)->number);
	//printf("Stack: %d",(state.sa->number));
	return 0;
}
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_s	state;

	state.sa = NULL;
	state.sb = NULL;
	if (argc < 2)
		return (EXIT_FAILURE);
	initialize_stack(argc, argv, &state);
	while (state.sa)
	{
		ft_printf("________\n%d\n",((t_s_c *)state.sa->content)->number);
		state.sa = state.sa->next;
	}
	return (EXIT_SUCCESS);
}