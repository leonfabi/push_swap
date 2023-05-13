/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:40:40 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/13 10:39:59 by fkrug            ###   ########.fr       */
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

void	ft_sanitize(t_s *stack)
{
	ft_lstclear(&(stack->sa), &free);
	ft_lstclear(&(stack->sb), &free);
}

void	ft_free_2d(char **tmp)
{
	int	count;

	count = 0;
	if (tmp != NULL)
	{
		while (tmp[count])
			free(tmp[count++]);
		free(tmp);
	}
}

int	ft_list_double(t_list *sa)
{
	int	nbr;
	
	if (sa->next)
		nbr = ((t_s_c *)(sa->content))->number;
	while (sa->next)
	{
		if (nbr == ((t_s_c *)(sa->next->content))->number)
			return (1);
		sa = sa->next;
	}
	return (0);
}