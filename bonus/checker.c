/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 07:51:26 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/25 15:39:08 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_operation_valid(char *str, int (*f)(const char *, const char *, size_t))
{
	int	i;

	i = 0;
	if (!(*f)(str, "rra\n", 4) || !(*f)(str, "rrb\n", 4) || !(*f)(str, "rrr\n", 4))
		i = 1;
	if (!(*f)(str, "ra\n", 3) || !(*f)(str, "rb\n", 3) || !(*f)(str, "rr\n", 3))
		i = 1;
	if (!(*f)(str, "sa\n", 3) || !(*f)(str, "sb\n", 3) || !(*f)(str, "ss\n", 3))
		i = 1;
	if (!(*f)(str, "pa\n", 3) || !(*f)(str, "pb\n", 3))
		i = 1;
	return (i);
}

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
	return (str);
}

int	ft_read_instructions(t_s *stp)
{
	char	*str;

	str = get_next_line(STDIN_FILENO);
	while (str && ft_operation_valid(str, ft_strncmp))
	{
		ft_operation_exec(str, stp);
		free (str);
		str = get_next_line(STDIN_FILENO);
	}
	if (str != NULL && !ft_operation_valid(str, ft_strncmp))
		return (1);
	return (0);
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
	if (ft_read_instructions(&stacks))
		ft_putendl_fd("Error", STDERR_FILENO);
	else
	{
		if (ft_is_sorted(&stacks) && !ft_lstsize(stacks.sb))
			ft_putstr_fd("OK", STDOUT_FILENO);
		else
			ft_putstr_fd("KO", STDOUT_FILENO);
	}
	ft_sanitize(&stacks);
	return (1);
}
