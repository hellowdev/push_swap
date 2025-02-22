/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheap_a_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:18:03 by ychedmi           #+#    #+#             */
/*   Updated: 2025/02/22 13:28:40 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*cheap_move(t_list *stack_a, t_list *stack_b)
{
	t_list	*holder;

	totale_move(stack_a, stack_b);
	holder = stack_a;
	while (stack_a)
	{
		if (stack_a->next && holder->moves > stack_a->next->moves)
		{
			holder = stack_a->next;
		}
		stack_a = stack_a->next;
	}
	return (holder);
}

void	same_moves(t_list **stack_a, t_list **stack_b, t_list *cheapnode)
{
	if (cheapnode->position <= ft_lstsize(*stack_a) / 2 \
	&& cheapnode->tar_index <= ft_lstsize(*stack_b) / 2)
	{
		while (cheapnode->position > 0 && cheapnode->tar_index > 0)
		{
			rr(stack_a, stack_b);
			cheapnode->position--;
			cheapnode->tar_index--;
		}
	}
	else if (cheapnode->position > ft_lstsize(*stack_a) / 2 \
	&& cheapnode->tar_index > ft_lstsize(*stack_b) / 2)
	{
		while ((cheapnode->position < ft_lstsize(*stack_a) \
		&& cheapnode->tar_index < ft_lstsize(*stack_b)))
		{
			rrr(stack_a, stack_b);
			cheapnode->position++;
			cheapnode->tar_index++;
		}
	}
}

void	rotations_move(t_list **stack_a, t_list **stack_b, t_list *cheapnode)
{
	while (cheapnode->position <= ft_lstsize(*stack_a) / 2 \
	&& cheapnode->position > 0)
	{
		ra(stack_a);
		cheapnode->position--;
	}
	while (cheapnode->position > ft_lstsize(*stack_a) / 2 \
	&& cheapnode->position < ft_lstsize(*stack_a))
	{
		rra(stack_a);
		cheapnode->position++;
	}
	while (cheapnode->tar_index <= ft_lstsize(*stack_b) / 2 \
	&& cheapnode->tar_index > 0)
	{
		rb(stack_b);
		cheapnode->tar_index--;
	}
	while (cheapnode->tar_index > ft_lstsize(*stack_b) / 2 \
	&& cheapnode->tar_index < ft_lstsize(*stack_b))
	{
		rrb(stack_b);
		cheapnode->tar_index++;
	}
}

void	sort_a_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapnode;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while ((*stack_a) && ft_lstsize(*stack_a) != 3)
	{
		init_tar_pos(*stack_a, *stack_b);
		cheapnode = cheap_move(*stack_a, *stack_b);
		if ((cheapnode->position <= ft_lstsize(*stack_a) / 2 \
		&& cheapnode->tar_index <= ft_lstsize(*stack_b) / 2) \
		|| (cheapnode->position > ft_lstsize(*stack_a) / 2 \
		&& cheapnode->tar_index > ft_lstsize(*stack_b) / 2))
			same_moves(stack_a, stack_b, cheapnode);
		rotations_move(stack_a, stack_b, cheapnode);
		pb(stack_a, stack_b);
	}
	sortthree(stack_a);
}
