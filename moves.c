#include "push_swap.h"

void	sa(t_list *stack_a)
{
	long tmp;
	
	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = tmp;
	write(1, "sa\n", 3);
}
void	sb(t_list *stack_b)
{
	long tmp;
	
	tmp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = tmp;
	write(1, "sb\n", 3);
}
void	ss(t_list *stack_a, t_list *stack_b)
{
	long tmp;
	
	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = tmp;

	tmp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = tmp;
	write(1, "ss\n", 3);
}
void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;
	
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;
	
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "pb\n", 3);
}
void	ra(t_list **stack_a)
{
	t_list *tmp = *stack_a;
	
	tmp = ft_lstlast(tmp);
	tmp->next = *stack_a;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}
void	rb(t_list **stack_b)
{
	t_list *tmp = *stack_b;
	
	tmp = ft_lstlast(tmp);
	tmp->next = *stack_b;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}
void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp = *stack_a;
	
	tmp = ft_lstlast(tmp);
	tmp->next = * stack_a;
	tmp = * stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	
	tmp = *stack_b;
	
	tmp = ft_lstlast(tmp);
	tmp->next = *stack_b;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	write(1, "rr\n", 3);
}
void 	rra(t_list **stack_a)
{
	t_list *tmp = *stack_a;
	t_list *last = *stack_a;
	
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
	t_list *tmp = *stack_b;
	t_list *last = *stack_b;
	
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
	t_list *tmp;
	t_list *last;
	tmp = *stack_a;
	last = *stack_a;
//	RRA //
	last = ft_lstlast(last);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last->next = (*stack_a);
	tmp->next = NULL;
	*stack_a = last;
//	RRB //
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
