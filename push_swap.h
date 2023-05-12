/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:24:36 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/12 16:12:39 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "Libft/libft.h"
#include "limits.h"

typedef struct s_stack_content{
	int	number;
	int	position;
}	t_s_c;
typedef struct s_stack{
	t_list	*sa;
	t_list	*sb;
}	t_s;

//Helper functions
t_s_c	*ft_contentnew(int number, int position);
void	ft_sanitize(t_s *stack);
int	is_str_valid(char *str);

#endif