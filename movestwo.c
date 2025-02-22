/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movestwo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:39:26 by ychedmi           #+#    #+#             */
/*   Updated: 2025/02/22 12:40:16 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stack_a)
{
	long	tmp;

	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_list *stack_b)
{
	long	tmp;

	tmp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	long	tmp;

	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = tmp;
	tmp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = tmp;
	write(1, "ss\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "pb\n", 3);
}
