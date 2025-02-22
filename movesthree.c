/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesthree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:40:26 by ychedmi           #+#    #+#             */
/*   Updated: 2025/02/22 12:43:40 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack_a;
	last = *stack_a;
	last = ft_lstlast(last);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last->next = (*stack_a);
	tmp->next = NULL;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack_b;
	last = *stack_b;
	last = ft_lstlast(last);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last->next = (*stack_b);
	tmp->next = NULL;
	*stack_b = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack_a;
	last = *stack_a;
	last = ft_lstlast(last);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last->next = (*stack_a);
	tmp->next = NULL;
	*stack_a = last;
	tmp = *stack_b;
	last = *stack_b;
	last = ft_lstlast(last);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last->next = (*stack_b);
	tmp->next = NULL;
	*stack_b = last;
	write(1, "rrr\n", 4);
}
