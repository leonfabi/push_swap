/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_input2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 10:32:05 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/26 00:19:00 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(t_s *stack_ptr, char **tmp, int error)
{
	if (error == 1)
	{
		ft_sanitize(stack_ptr);
		if (tmp != NULL)
			ft_free_2d(tmp);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (1);
	}
	else
		return (0);
}

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
			i++;
		while (i--)
		{
			if (ft_error(stp, tmp, !is_str_valid(tmp[i])))
				return (-1);
			ft_lstadd_front(&(stp->sa), ft_lstnew(ft_cnew(ft_atoi(tmp[i]), 0)));
			length++;
		}
		if (ft_error(stp, tmp, ft_list_double(stp->sa)))
			return (-1);
		else
			ft_free_2d(tmp);
	}
	return (length);
}
