/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_algo3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:59:26 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/19 15:33:16 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_chunk(int position, int size, int chunk_size, t_s *stp)
{
	int	i;

	i = 0;
	while (i * chunk_size <= stp->length - size)
		i++;
	//ft_printf("Initial length:%d\nRemaining size:%d\nAllowed numbers:%d\nposition:%d\n", stp->length, size, i*chunk_size, position);
	//if (position <= i * chunk_size && position >= (i - 1) * chunk_size)
	if (position <= i * chunk_size)
		return (1);
	return (0);
}
