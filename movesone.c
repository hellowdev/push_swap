/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:36:29 by ychedmi           #+#    #+#             */
/*   Updated: 2025/02/22 12:39:11 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	tmp = ft_lstlast(tmp);
	tmp->next = *stack_a;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	tmp = ft_lstlast(tmp);
	tmp->next = *stack_b;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	tmp = ft_lstlast(tmp);
	tmp->next = *stack_a;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	tmp = *stack_b;
	tmp = ft_lstlast(tmp);
	tmp->next = *stack_b;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	write(1, "rr\n", 3);
}
