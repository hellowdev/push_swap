/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:39:26 by ychedmi           #+#    #+#             */
/*   Updated: 2025/02/23 14:50:29 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_list *stack_a)
{
	long	tmp;

	if (ft_lstsize(stack_a) > 1)
	{
		tmp = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = tmp;
	}
}

void	sb(t_list *stack_b)
{
	long	tmp;

	if (ft_lstsize(stack_b) > 1)
	{
		tmp = stack_b->content;
		stack_b->content = stack_b->next->content;
		stack_b->next->content = tmp;
	}
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
}
