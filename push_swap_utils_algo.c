/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_algo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:03:26 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/23 14:28:31 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubbleSort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_parse(t_s *stp, int *arr, int size)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = stp->sa;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == ((t_s_c *)tmp->c)->number)
			{
				((t_s_c *)tmp->c)->p = i;
				i = size;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	ft_init_p(t_s *stp)
{
	int	*array;
	int	length;
	int	i;
	t_list	*tmp;

	tmp = stp->sa;
	i = 0;
	length = ft_lstsize(tmp);
	array = malloc(length * sizeof(int));
	if (array == NULL)
		return ;
	while (i < length)
	{
		array[i++] = ((t_s_c *)tmp->c)->number;
		tmp = tmp->next;
	}
	ft_bubbleSort(array, length);
	ft_parse(stp, array, length);
	free(array);
}

int	ft_is_sorted(t_s *stp)
{
	t_list	*tmp;
	int		a;
	int		b;

	tmp = stp->sa;
	while(tmp->next)
	{
		a = ((t_s_c *)tmp->c)->number;
		b = ((t_s_c *)tmp->next->c)->number;
		if (a > b)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_sort_3(t_s *stp)
{
	int	a;
	int	b;
	int	c;

	a = ((t_s_c *)stp->sa->c)->number;
	b = ((t_s_c *)stp->sa->next->c)->number;
	c = ((t_s_c *)stp->sa->next->next->c)->number;
	if (ft_is_sorted(stp))
		return ;
	else if (a > b && c > a && c > b)
		return (ft_swap(stp, "sa"));
	else if (a > c && a > b && c > b)
		return (ft_rotate(stp, "ra"));
	else if (a >c && a < b && b > c)
		return (ft_rotate(stp, "rra"));
	ft_swap(stp, "sa");
	if (a > b)
		return (ft_rotate(stp, "rra"));
	else
		return (ft_rotate(stp, "ra"));
}
