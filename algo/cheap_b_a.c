/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheap_b_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:29:15 by ychedmi           #+#    #+#             */
/*   Updated: 2025/02/22 13:34:59 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	target_a(t_list *stack_a, t_list *stack_b)
{
	int	holder;
	int	result;
	int	i;
	int	j;

	j = 0;
	i = 0;
	holder = (stack_a->content) - (stack_b->content);
	stack_a = stack_a->next;
	while (stack_a)
	{
		result = (stack_a->content) - (stack_b->content);
		if ((holder > result && result > 0) || (holder < 0 && result > 0) \
		|| (holder < 0 && result < 0 && holder > result))
		{
			holder = ((stack_a->content) - (stack_b->content));
			j = i + 1;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (stack_b->tar_index = j);
}

void	init_targ(t_list *stack_a, t_list *stack_b)
{
	int		index;
	t_list	*tmp;

	tmp = stack_b;
	index = 0;
	while (stack_b)
	{
		target_a(stack_a, stack_b);
		stack_b = stack_b->next;
	}
	while (tmp)
	{
		tmp->position = index++;
		tmp = tmp->next;
	}
}

void	sec_rotations(t_list **stack_a, t_list **stack_b, t_list *cheapnode)
{
	while (cheapnode->position <= ft_lstsize(*stack_b) / 2 \
	&& cheapnode->position > 0)
	{
		rb(stack_b);
		cheapnode->position--;
	}
	while (cheapnode->position > ft_lstsize(*stack_b) / 2 \
	&& cheapnode->position < ft_lstsize(*stack_b))
	{
		rrb(stack_b);
		cheapnode->position++;
	}
	while (cheapnode->tar_index <= ft_lstsize(*stack_a) / 2 \
	&& cheapnode->tar_index > 0)
	{
		ra(stack_a);
		cheapnode->tar_index--;
	}
	while (cheapnode->tar_index > ft_lstsize(*stack_a) / 2 \
	&& cheapnode->tar_index < ft_lstsize(*stack_a))
	{
		rra(stack_a);
		cheapnode->tar_index++;
	}
}

void	sort_b_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapnode;

	while ((*stack_b))
	{
		init_targ(*stack_a, *stack_b);
		cheapnode = cheap_move(*stack_b, *stack_a);
		if ((cheapnode->position <= ft_lstsize(*stack_b) / 2 \
		&& cheapnode->tar_index <= ft_lstsize(*stack_a) / 2) \
		|| (cheapnode->position > ft_lstsize(*stack_b) / 2 \
		&& cheapnode->tar_index > ft_lstsize(*stack_a) / 2))
			same_moves(stack_b, stack_a, cheapnode);
		sec_rotations(stack_a, stack_b, cheapnode);
		pa(stack_a, stack_b);
	}
	while (minindex(*stack_a) > 0 \
	&& minindex(*stack_a) <= ft_lstsize(*stack_a) / 2)
		ra(stack_a);
	while (minindex(*stack_a) > ft_lstsize(*stack_a) / 2)
		rra(stack_a);
}
