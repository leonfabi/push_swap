/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_operations.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:02:58 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/13 14:12:38 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_s *stp, char *operation)
{
	t_list	*tmp;

	tmp = NULL;
	if (!ft_strncmp(operation, "ss", 3))
		ft_swap_ss(stp);
	else if (!ft_strncmp(operation, "sa", 3))
	{
		if (ft_lstsize(stp->sa) < 2)
			return;
		tmp = stp->sa;
		stp->sa = stp->sa->next;
		tmp->next = stp->sa->next;
		stp->sa->next = tmp;
		ft_putendl_fd(operation,STDOUT_FILENO);
	}
	else if (!ft_strncmp(operation, "sb", 3))
	{
		if (ft_lstsize(stp->sb) < 2)
			return;
		tmp = stp->sb;
		stp->sb = stp->sb->next;
		tmp->next = stp->sb->next;
		stp->sb->next = tmp;
		ft_putendl_fd(operation,STDOUT_FILENO);
	}
}

void	ft_swap_ss(t_s *stp)
{
	t_list	*tmp;

	tmp = NULL;
	if (ft_lstsize(stp->sa) < 2)
		return;
	if (ft_lstsize(stp->sb) < 2)
		return;
	tmp = stp->sa;
	stp->sa = stp->sa->next;
	tmp->next = stp->sa->next;
	stp->sa->next = tmp;
	tmp = NULL;
	tmp = stp->sb;
	stp->sb = stp->sb->next;
	tmp->next = stp->sb->next;
	stp->sb->next = tmp;
	ft_putendl_fd("ss", STDOUT_FILENO);
}
void	ft_push(t_s *stp, char *operation)
{
	t_list	*tmp;

	tmp = NULL;
	if (!ft_strncmp(operation, "pa", 3))
	{
		if (stp->sa == NULL)
			return;
		tmp = stp->sb;
		stp->sb = stp->sa;
		stp->sa = stp->sa->next;
		stp->sb->next = tmp;
		ft_putendl_fd(operation, STDOUT_FILENO);
	}
	else if (!ft_strncmp(operation, "pb", 3))
	{
		if (stp->sb == NULL)
			return;
		tmp = stp->sa;
		stp->sa = stp->sb;
		stp->sb = stp->sb->next;
		stp->sa->next = tmp;
		ft_putendl_fd(operation, STDOUT_FILENO);
	}
}
