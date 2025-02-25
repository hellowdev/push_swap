/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:13:24 by ychedmi           #+#    #+#             */
/*   Updated: 2025/02/25 15:50:49 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_target(t_list *stack_a, t_list *stack_b)
{
	int	holder;
	int	result;
	int	i;
	int	j;

	j = 0;
	i = 0;
	holder = (stack_a->content) - (stack_b->content);
	stack_b = stack_b->next;
	while (stack_b)
	{
		result = (stack_a->content) - (stack_b->content);
		if ((holder > result && result > 0) || (holder < 0 && result > 0) \
		|| (holder < 0 && result < 0 && holder > result))
		{
			holder = result;
			j = i + 1;
		}
		stack_b = stack_b->next;
		i++;
	}
	return (stack_a->tar_index = j);
}

void	init_tar_pos(t_list *stack_a, t_list *stack_b)
{
	int		index;
	t_list	*tmp;

	tmp = stack_a;
	index = 0;
	while (stack_a)
	{
		ft_target(stack_a, stack_b);
		stack_a = stack_a->next;
	}
	while (tmp)
	{
		tmp->position = index++;
		tmp = tmp->next;
	}
}

int	moves_b(t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	half;
	int	x;

	x = 0;
	i = 0;
	half = ft_lstsize(stack_b) / 2;
	i = stack_a->tar_index;
	if (i <= half)
		x = i;
	else
		x = ft_lstsize(stack_b) - i;
	return (x);
}

int	moves_a(t_list *stack_a, t_list *lst)
{
	int	i;
	int	half;
	int	x;

	x = 0;
	i = 0;
	half = ft_lstsize(lst) / 2;
	i = stack_a->position;
	if (i <= half)
		x = i;
	else
		x = ft_lstsize(lst) - i;
	return (x);
}

void	totale_move(t_list *stack_a, t_list *stack_b)
{
	int		halfa;
	int		halfb;
	t_list	*lst;

	lst = stack_a;
	halfa = ft_lstsize(stack_a) / 2;
	halfb = ft_lstsize(stack_b) / 2;
	while (stack_a)
	{
		if ((stack_a->position <= halfa && stack_a->tar_index <= halfb) \
		|| (stack_a->position > halfa && stack_a->tar_index > halfb))
		{
			if (moves_a(stack_a, lst) > moves_b(stack_a, stack_b))
				stack_a->moves = moves_a(stack_a, lst);
			else
				stack_a->moves = moves_b(stack_a, stack_b);
		}
		else
			stack_a->moves = moves_a(stack_a, lst) + moves_b(stack_a, stack_b);
		stack_a = stack_a->next;
	}
}
