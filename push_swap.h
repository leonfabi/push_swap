/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:24:36 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/23 19:11:50 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "limits.h"

typedef struct s_stack_content{
	int	number;
	int	p;
}	t_s_c;
typedef struct s_stack{
	t_list	*sa;
	t_list	*sb;
	int		length;
}	t_s;

//Helper functions
t_s_c	*ft_cnew(int number, int p);
int		ft_sanitize(t_s *stack);
int		is_str_valid(char *str);
void	ft_free_2d(char **tmp);
int		ft_list_double(t_list *sa);
int		ft_error(t_s *stack_ptr, char **tmp, int error);
void	ft_put_stack(t_s *stp);
void	ft_init_p(t_s *stp);
int		ft_is_sorted(t_s *stp);
int		initialize_stack(int argc, char **argv, t_s *stp);

//Operations
void	ft_swap(t_s *stp, char *operation);
void	ft_swap_ss(t_s *stp);
void	ft_push(t_s *stp, char *operation);
void	ft_rotate(t_s *stp, char *operation);

//Algorithm
void	ft_sort_3(t_s *stp);
void	ft_sort(t_s *stp);
int		ft_is_chunk(int p, int size, int chunk_size, t_s *stp);
void	ft_call_sort_algo(t_s *stp);
int		ft_find_final_p_in_a(t_s *stp, int p);
int		ft_rotate_top(t_s *stp, int p, char *stack, int rev);
int		ft_calc_moves(t_s *stp, int p);

#endif