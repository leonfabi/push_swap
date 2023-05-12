/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:22:42 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/12 16:37:02 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
			printf("Funktion call add front\nsizeof t_s_c: %d\n",(int)sizeof(t_s_c));
			count++;
		}
		//doppelte zahlen
	}
	count = 0;
	while (tmp[count])
		free(tmp[count++]);
	free(tmp);
	return 0;
}
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
	//free(&(state.sa->content));
	//free(state.sa);
	//ft_sanitize(&state);
	return (EXIT_SUCCESS);
}