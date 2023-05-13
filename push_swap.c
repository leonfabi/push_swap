/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:22:42 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/13 10:48:44 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	initialize_stack(int argc, char **argv, t_s *stp)
{
	int		i;
	char	**tmp;

	i = 0;
	while (argc-- > 1)
	{
		tmp = ft_split(argv[argc], ' ');
		i = 0;
		while (tmp[i])
		{
			if (ft_error(stp, tmp, !is_str_valid(tmp[i])))
				return (0);
			ft_lstadd_front(&(stp->sa), ft_lstnew(ft_cnew(ft_atoi(tmp[i]), 0)));
			i++;
		}
		if (ft_error(stp, tmp, ft_list_double(stp->sa)))
			return (0);
		else
			ft_free_2d(tmp);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_s	stacks;

	stacks.sa = NULL;
	stacks.sb = NULL;
	if (argc < 2)
		return (EXIT_FAILURE);
	initialize_stack(argc, argv, &stacks);
	ft_sanitize(&stacks);
	return (EXIT_SUCCESS);
}
