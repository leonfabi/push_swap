/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:22:42 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/11 20:26:30 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_error(int argc, char **argv)
{

}
int	initialize_stack(int argc, char **argv, t_s state)
{
	int		count;
	char	**tmp;
	t_s_c	values;

	count = 0;
	values.number = 42;
	values.position = 3;
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
			values.number = ft_atoi(tmp[count]);
			ft_lstadd_front(&state.sa, ft_lstnew(&values));
			count++;
		}
		//doppelte zahlen
	}
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
	initialize_stack(argc, argv, state);
	printf("Stack: %d",((t_s_c*)state.sa->content)->number);
	// while (state.sa->next)
	// {
	// 	ft_printf("_\n%d\n_",state.sa->content);
	// 	state.sa = state.sa->next;
	// }
	return (EXIT_SUCCESS);
}