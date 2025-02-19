#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
#include <limits.h>

// CHECK ERRORS //
int checkdig(char *str);
int checksp(char *str);
void retatoi(char *p, t_list **stack_a);
int checkdb(t_list *look);
//MOVES FUNCTIONS //
void	sa(t_list *head);
void	sb(t_list *head);
void	ss(t_list *stack_a, t_list *stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void 	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

void sort2nb(t_list *stack_a);
void sort3nb(t_list **stack_a);
void	minisort(t_list **stack_a);
int minindex(t_list *stack_a);
int	checksorting(t_list *stack_a);

// B to A //
int     target_a(t_list *stack_a, t_list *stack_b);
void	init_targ(t_list *stack_a, t_list *stack_b);
void	sort_b_a(t_list **stack_a, t_list **stack_b);
t_list	*cheap_move(t_list *stack_a, t_list *stack_b);
void    first_move(t_list **stack_a, t_list **stack_b, t_list *cheapnode);
void    sec_move(t_list **stack_a, t_list **stack_b, t_list *cheapnode);


#endif