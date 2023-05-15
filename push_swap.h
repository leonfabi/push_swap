/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:24:36 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/15 10:52:46 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "limits.h"

typedef struct s_stack_content{
	int	number;
	int	position;
}	t_s_c;
typedef struct s_stack{
	t_list	*sa;
	t_list	*sb;
}	t_s;

//Helper functions
t_s_c	*ft_cnew(int number, int position);
void	ft_sanitize(t_s *stack);
int		is_str_valid(char *str);
void	ft_free_2d(char **tmp);
int		ft_list_double(t_list *sa);
int		ft_error(t_s *stack_ptr, char **tmp, int error);
void	ft_put_stack(t_s *stp);
void	ft_init_position(t_s *stp);

//Operations
void	ft_swap(t_s *stp, char *operation);
void	ft_swap_ss(t_s *stp);
void	ft_push(t_s *stp, char *operation);
void	ft_rotate(t_s *stp, char *operation);


#endif