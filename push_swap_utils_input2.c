/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_input2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 10:32:05 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/13 13:59:16 by fkrug            ###   ########.fr       */
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
void	ft_put_stack(t_s *stp)
{
	t_list	*tmp;

	tmp = stp->sa;
	ft_printf("Print stack a:\n______\n");
	while (tmp)
	{
		ft_printf("%d\n_____\n",((t_s_c *)tmp->content)->number);
		tmp = tmp->next;
	}
	ft_printf("END\n");
	tmp = stp->sb;
	ft_printf("Print stack b:\n______\n");
	while (tmp)
	{
		ft_printf("%d\n_____\n",((t_s_c *)tmp->content)->number);
		tmp = tmp->next;
	}
	ft_printf("END\n");
}
