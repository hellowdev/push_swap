/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:36:29 by ychedmi           #+#    #+#             */
/*   Updated: 2025/02/23 14:50:57 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_list **stack_a)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_a) > 1)
	{
		tmp = *stack_a;
		tmp = ft_lstlast(tmp);
		tmp->next = *stack_a;
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
	}
}

void	rb(t_list **stack_b)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_b) > 1)
	{
		tmp = *stack_b;
		tmp = ft_lstlast(tmp);
		tmp->next = *stack_b;
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
