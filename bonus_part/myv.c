/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:40:26 by ychedmi           #+#    #+#             */
/*   Updated: 2025/02/23 10:23:21 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*stack_a) > 1)
	{
		tmp = *stack_a;
		last = *stack_a;
		last = ft_lstlast(last);
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		last->next = (*stack_a);
		tmp->next = NULL;
		*stack_a = last;
	}
}

void	rrb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*stack_b) > 1)
	{
		tmp = *stack_b;
		last = *stack_b;
		last = ft_lstlast(last);
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		last->next = (*stack_b);
		tmp->next = NULL;
		*stack_b = last;
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
