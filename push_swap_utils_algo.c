/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_algo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:03:26 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/15 11:24:04 by fkrug            ###   ########.fr       */
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

void	ft_init_position(t_s *stp)
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
		array[i++] = ((t_s_c *)tmp->content)->number;
		tmp = tmp->next;
	}
	ft_bubbleSort(array, length);
	i = 0;
	while (i++ < length)
		ft_printf("%d\n",array[i-1]);
	free(array);
}

