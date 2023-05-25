/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 07:51:26 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/25 10:22:30 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_str_valid(char *str, int	(*f)(const char *,const char *, size_t))
{
	int	i;

	i = 0;
	ft_printf("Return value of (*f): %d\n", (*f)(str, "rra\n", 5));
	if (!(*f)(str, "rra\n", 5) || !(*f)(str, "rrb\n", 5) || !(*f)(str, "rrr\n", 5))
		i = 1;
	if (!(*f)(str, "ra\n", 4) || !(*f)(str, "rb\n", 4) || !(*f)(str, "rr\n", 4))
		i = 1;
	if (!(*f)(str, "sa\n", 4) || !(*f)(str, "sb\n", 4) || !(*f)(str, "ss\n", 4))
		i = 1;
	if (!(*f)(str, "pa\n", 4) || !(*f)(str, "pb\n", 4))
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

void	ft_read_instructions(t_s *stp)
{
	char	*str;

	str = get_next_line(STDIN_FILENO);
	while (str)
	{
		ft_operation_exec(str, stp);
		ft_printf("Input valid?: %d\n", ft_str_valid(str, ft_strncmp));
		free (str);
		str = get_next_line(STDIN_FILENO);
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
	if (ft_is_sorted(&stacks))
		ft_putstr_fd("OK", STDOUT_FILENO);
	else
		ft_putstr_fd("KO", STDOUT_FILENO);
	ft_sanitize(&stacks);
	return (1);
}
