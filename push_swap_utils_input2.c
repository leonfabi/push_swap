/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_input2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 10:32:05 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/13 10:50:08 by fkrug            ###   ########.fr       */
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
