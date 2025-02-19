/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:14:30 by ychedmi           #+#    #+#             */
/*   Updated: 2025/02/19 18:14:37 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int ft_target(t_list *stack_a, t_list *stack_b)
{
	int holder;
	int result;
	int i;
	int j;
	j = 0;
	i = 0;
	
	holder = (stack_a->content) - (stack_b->content);
	stack_b = stack_b->next;
	
	while (stack_b)
	{	
		result = (stack_a->content) - (stack_b->content);
		
		if ((holder > result && result > 0) || (holder < 0 && result > 0) || (holder < 0 && result < 0 && holder > result ))
		{
			holder = ((stack_a->content) - (stack_b->content));
			j = i + 1;
		}
		stack_b = stack_b->next;
		i++;
	}
	return (stack_a->tar_index = j);
}

void	init_tar_pos(t_list *stack_a, t_list *stack_b)
{
	int index;
	t_list *tmp = stack_a;
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

int	moves_b(t_list *stack_a, t_list *lst)
{
	int i;
	int half;
	int x;
	x = 0;
	i = 0;

	half = ft_lstsize(lst) / 2;
	i = stack_a->tar_index;
	
	if (i <= half)
		x = i;
	else
		x = ft_lstsize(lst) - i;
	// printf("totMOVe B >> %d\n", x);
	return (x);
}
int	moves_a(t_list *stack_a, t_list *lst)
{
	int i;
	int half;
	int x;
	x = 0;
	i = 0;

	half = ft_lstsize(stack_a) / 2;
	i = stack_a->position;
	
	if (i <= half)
		x = i;
	else
		x = ft_lstsize(lst) - i;
	// printf("totMOVe A >> %d\n", x);
	return (x);
}

void	totale_move(t_list *stack_a, t_list *stack_b)
{
	int halfa;
	int halfb;
	t_list *lst;
	lst = stack_a;
	halfa = ft_lstsize(stack_a) / 2;
	halfb = ft_lstsize(stack_b) / 2;
	
	while (stack_a)
	{
		if ((stack_a->position <= halfa && stack_a->tar_index <= halfb) || (stack_a->position > halfa && stack_a->tar_index > halfb))
		{
			if (moves_a(stack_a, lst) > moves_b(stack_a, stack_b))
				stack_a->moves = moves_a(stack_a, lst);
			else
				stack_a->moves = moves_b(stack_a, stack_b);
		}
		else
			stack_a->moves = moves_a(stack_a, lst) + moves_b(stack_a, stack_b);
		
		// printf("stackB moves >> %d\n", stack_a->moves);
		stack_a = stack_a->next;
	}
}

t_list	*cheap_move(t_list *stack_a, t_list *stack_b)
{
	totale_move(stack_a, stack_b);
	
	t_list *holder;
	
	holder = stack_a;
	
	while (stack_a)
	{
		
		if (stack_a->next && holder->moves > stack_a->next->moves)
		{
			holder = stack_a->next;
		}
		// printf("st >> %ld\n", holder->content);
		stack_a = stack_a->next;
	}
	// printf("cheap content >>>>>>>>>>>>>>>>> %ld\n", holder->content);
	// printf("cheap moves >>>>>>>>>>>>>>>>> %d\n", holder->moves);
	return (holder);
}

void first_move(t_list **stack_a, t_list **stack_b, t_list *cheapnode)
{	
		
		if (cheapnode->position <= ft_lstsize(*stack_a) / 2 && cheapnode->tar_index <= ft_lstsize(*stack_b) / 2)
		{
			while (cheapnode->position > 0 && cheapnode->tar_index > 0) // while (checker(t_list *stack_a, t_list *stach_b) == 1)
			{
				rr(stack_a, stack_b);
				cheapnode->position--;
				cheapnode->tar_index--;
			}
		}
		else if (cheapnode->position > ft_lstsize(*stack_a) / 2 && cheapnode->tar_index > ft_lstsize(*stack_b) / 2)
			while ((cheapnode->position < ft_lstsize(*stack_a) && cheapnode->tar_index < ft_lstsize(*stack_b)))
			{
				rrr(stack_a, stack_b);
				cheapnode->position++;
				cheapnode->tar_index++;
			}
}
void sec_move(t_list **stack_a, t_list **stack_b, t_list *cheapnode)
{	
			
	while (cheapnode->position <= ft_lstsize(*stack_a) / 2 && cheapnode->position > 0)
	{
		ra(stack_a);
		cheapnode->position--;
	}			
	while (cheapnode->position > ft_lstsize(*stack_a) / 2 && cheapnode->position < ft_lstsize(*stack_a))
	{
		rra(stack_a);
		cheapnode->position++;
	}
	while (cheapnode->tar_index <= ft_lstsize(*stack_b) / 2 && cheapnode->tar_index > 0)
	{
		rb(stack_b);
		cheapnode->tar_index--;
	}
	while (cheapnode->tar_index > ft_lstsize(*stack_b) / 2 && cheapnode->tar_index < ft_lstsize(*stack_b))
	{
		rrb(stack_b);
		cheapnode->tar_index++;
	}
}

void	sort_a_b(t_list **stack_a, t_list **stack_b)
{
	t_list *cheapnode;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	
	while ((*stack_a) && ft_lstsize(*stack_a) != 3)
	{
		init_tar_pos(*stack_a, *stack_b);
		cheapnode = cheap_move(*stack_a, *stack_b);
		
		if ((cheapnode->position <= ft_lstsize(*stack_a) / 2 && cheapnode->tar_index <= ft_lstsize(*stack_b) / 2)\
		|| (cheapnode->position > ft_lstsize(*stack_a) / 2 && cheapnode->tar_index > ft_lstsize(*stack_b) / 2))
			first_move(stack_a, stack_b, cheapnode);
		sec_move(stack_a, stack_b, cheapnode);
		
		pb(stack_a, stack_b);
	}
	sort3nb(stack_a);
}



int main(int ac, char *av[])
{
	int i;
	t_list *stack_a;
	t_list *stack_b = NULL;

	stack_a = NULL;
	i = 0;
	
	while (++i < ac)
		if (checkdig(av[i]) == 1 || checksp(av[i]) == 1)
			return (write(2, "Error\n", 6), 0);
		else
			retatoi(av[i], &stack_a);
	if (checkdb(stack_a) == 1)
		return (write(2, "Error\n", 6), 0);

		
	sort_a_b(&stack_a, &stack_b);
	
	sort_b_a(&stack_a, &stack_b);

	
}


