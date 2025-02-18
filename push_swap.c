/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:14:30 by ychedmi           #+#    #+#             */
/*   Updated: 2025/02/18 21:07:50 by ychedmi          ###   ########.fr       */
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

int minindex(t_list *stack_a)
{
	int j;
	int holder;
	t_list *head;
	int i;
	
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
	
	return (stack_a->targetb = j);
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
	i = stack_a->targetb;
	
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

	half = ft_lstsize(lst) / 2;
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
		if ((stack_a->position <= halfa && stack_a->targetb <= halfb) || (stack_a->position > halfa && stack_a->targetb > halfb))
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
		stack_a = stack_a->next;
	}
	return (holder);
}
// int	checker(t_list *stack_a, t_list *stach_b)
// {
// 	int x;
// 	int y;

// 	while (stack_a)
// 	{
// 		t_list *cheapnode = cheap_move(*stack_a, *stack_b);
		
// 	}
	
// }

void best_move(t_list **stack_a, t_list **stack_b)
{	
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	
    while ((*stack_a) && ft_lstsize(*stack_a) != 3)
    {
		init_tar_pos(*stack_a, *stack_b);
		
	 	int size_a = ft_lstsize(*stack_a);
        int size_b = ft_lstsize(*stack_b);
		t_list *cheapnode = cheap_move(*stack_a, *stack_b);
		
		if (cheapnode->position <= size_a / 2 && cheapnode->targetb <= size_b / 2 && (cheapnode->position != 0 && cheapnode->targetb != 0))
			while (cheapnode->position > 0 && cheapnode->targetb > 0) // while (checker(t_list *stack_a, t_list *stach_b) == 1)
			{
				rr(stack_a, stack_b);
				cheapnode->position--;
				cheapnode->targetb--;
			}
		else if(cheapnode->position > size_a / 2 && cheapnode->targetb > size_b / 2)
			while ((cheapnode->position < size_a && cheapnode->targetb < size_b))
			{
				rrr(stack_a, stack_b);
				cheapnode->position++;
				cheapnode->targetb++;
			}
			while (cheapnode->position <= size_a / 2 && cheapnode->position > 0)
			{
				ra(stack_a);
				cheapnode->position--;
			}
				
			while (cheapnode->position > size_a / 2 && cheapnode->position < size_a)
			{
				rra(stack_a);
				cheapnode->position++;
			}
			while (cheapnode->targetb <= size_b / 2 && cheapnode->targetb > 0)
			{
				rb(stack_b);
				cheapnode->targetb--;
			}
			while (cheapnode->targetb > size_b / 2 && cheapnode->targetb < size_b)
			{
				rrb(stack_b);
				cheapnode->targetb++;
			}
			pb(stack_a, stack_b);
	}
}

int main(int ac, char *av[])
{
	int i;
	t_list *stack_a;
	t_list *stack_b = NULL;
	
	// stack_b = ft_lstnew(34);
	// stack_b->next = ft_lstnew(10);
	// stack_b->next->next = ft_lstnew(15);
	// stack_b->next->next->next = ft_lstnew(20);
	// stack_b->next->next->next->next = ft_lstnew(40);
	// stack_b->next->next = ft_lstnew(5);

	stack_a = NULL;
	i = 0;
	
	while (++i < ac)
		if (checkdig(av[i]) == 1 || checksp(av[i]) == 1)
			return (write(2, "Error\n", 6), 0);
		else
			retatoi(av[i], &stack_a);
	if (checkdb(stack_a) == 1)
		return (write(2, "Error\n", 6), 0);
	
	best_move(&stack_a, &stack_b);
	
	// while (stack_b)
	// {
	// 	// printf("MOVES A >> %d\n", moves_a(stack_a, tst));
	// 	printf("stack_b >> %ld\n", stack_b->content);
	// 	// printf("moves B >> %d\n", moves_b(stack_a, stack_b));
	// 	stack_b = stack_b->next;
	// }
	
}


