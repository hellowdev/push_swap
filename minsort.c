/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:24:59 by ychedmi           #+#    #+#             */
/*   Updated: 2025/02/22 12:27:54 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checksorting(t_list *stack_a)
{
	while (stack_a)
	{
		if (stack_a->next && stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	minindex(t_list *stack_a)
{
	int		j;
	int		holder;
	t_list	*head;
	int		i;

	head = stack_a->next;
	holder = (stack_a->content);
	j = 0;
	i = 0;
	while (head)
	{
		if (holder > head->content)
		{
			j = i + 1;
			holder = head->content;
		}
		i++;
		head = head->next;
	}
	return (j);
}

void	sortthree(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*head;

	tmp = *stack_a; 
	head = tmp->next;
	if (ft_lstsize(*stack_a) == 3)
	{
		if (tmp->content > head->content && tmp->content > head->next->content)
			ra(stack_a);
		else if (head->content > tmp->content \
		&& head->content > head->next->content)
			rra(stack_a);
	}
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(*stack_a);
}

void	sortfour(t_list **stack_a, t_list **stack_b)
{
	t_list	*checker;

	checker = *stack_a;
	if (minindex(checker) == 3)
		rra(stack_a);
	else if (minindex(checker) == 2)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (minindex(checker) == 1)
		ra(stack_a);
	pb(stack_a, stack_b);
	sortthree(stack_a);
	pa(stack_a, stack_b);
}
