/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 07:51:26 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/24 22:45:06 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_operation_exec(char *str, t_s *stp)
{
	if (str != NULL && ft_strlen(str) == 4)
	{
		if (str[3] == '\n')
			str[3] = 0;
		if (!ft_strncmp(str, "rra", 4) || !ft_strncmp(str, "rrb", 4))
			ft_rotate(stp, str);
		else if (!ft_strncmp(str, "rrr", 4))
			ft_rotate(stp, str);
	}
	else if (str != NULL && ft_strlen(str) == 3)
	{
		if (str[2] == '\n')
			str[2] = 0;
		if (!ft_strncmp(str, "pa", 3) || !ft_strncmp(str, "pb", 3))
			ft_push(stp, str);
		else if (!ft_strncmp(str, "sa", 3) || !ft_strncmp(str, "sb", 3))
			ft_swap(stp, str);
		else if (!ft_strncmp(str, "ss", 3))
			ft_swap_ss(stp);
		else if (!ft_strncmp(str, "ra", 3) || !ft_strncmp(str, "rb", 3))
			ft_rotate(stp, str);
		else if (!ft_strncmp(str, "rr", 3))
			ft_rotate(stp, str);
	}
	return str;
}

void	ft_read_instructions(t_s *stp)
{
	char	*str;

	while (ft_operation_exec(get_next_line(STDIN_FILENO), stp))
	{
		ft_printf("\n--------------------\n");
	}
}

int	main(int argc, char **argv)
{
	t_s	stacks;

	stacks.sa = NULL;
	stacks.sb = NULL;
	stacks.length = initialize_stack(argc, argv, &stacks);
	if (argc < 2 || stacks.length == -1)
		return (EXIT_FAILURE);
	ft_init_p(&stacks);
	ft_read_instructions(&stacks);
	ft_sanitize(&stacks);
	return (1);
}