#include "push_swap.h"

void sort2nb(t_list *stack_a)
{
	
	if (stack_a->content > stack_a->next->content)
		sa(stack_a);
}
void sort3nb(t_list **stack_a)
{
	t_list *tmp;
	t_list *head;
	
	tmp = *stack_a; 
	head = tmp->next;

	if (tmp->content > head->content && tmp->content > head->next->content)
		ra(stack_a);
	else if (head->content > tmp->content && head->content > head->next->content)
		rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(*stack_a);
}
void sort4nb(t_list **stack_a, t_list **stack_b)
{
	t_list *checker;
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
	sort3nb(stack_a);
	pa(stack_a, stack_b);
}

void sort5nb(t_list **stack_a, t_list **stack_b)
{
	t_list *check;
	
	check = *stack_a;
	
	if (minindex(check) == 4)
		rra(stack_a);		
	else if (minindex(check) == 3)
	{
			rra(stack_a);
			rra(stack_a);
	}
	else if (minindex(check) == 2)
	{
			ra(stack_a);
			ra(stack_a);
	}
	else
		ra(stack_a);
	pb(stack_a, stack_b);
	sort4nb(stack_a, stack_b);
	pa(stack_a, stack_b);
}
void	minisort(t_list **stack_a, t_list **stack_b)
{
	if (checksorting(*stack_a) == 0 && ft_lstsize(*stack_a) == 3)
			sort3nb(stack_a);
	else if (checksorting(*stack_a) == 0 && ft_lstsize(*stack_a) == 4)
			sort4nb(stack_a, stack_b);
	else if (checksorting(*stack_a) == 0 && ft_lstsize(*stack_a) == 5)
			sort5nb(stack_a, stack_b);
	else if (checksorting(*stack_a) == 0 && ft_lstsize(*stack_a) == 2)
			sort2nb(*stack_a);
}