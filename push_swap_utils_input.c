/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:40:40 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/12 14:44:20 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_str_valid(char *str)
{
	char		*tmp;
	long long	nbr;

	tmp = str;
	if (*tmp == '+' || *tmp == '-')
		tmp++;
	if (!*tmp)
		return (0);
	while (*tmp)
	{
		if (!ft_isdigit(*tmp))
			return (0);
		tmp++;
	}
	nbr = ft_atoi(str);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return (1);
}

t_s_c	*ft_contentnew(int number, int position)
{
	t_s_c	*start;

	start = (t_s_c *)malloc(sizeof(t_s_c));
	if (start == NULL)
		return (NULL);
	start->number = number;
	start->position = position;
	return (start);
}