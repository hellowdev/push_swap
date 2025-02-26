/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:44:26 by ychedmi           #+#    #+#             */
/*   Updated: 2025/02/26 20:45:20 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

//----------CHECK ERRORS---------//
int		checkdig(char *str);
int		checksp(char *str);
int		checkdb(t_list *look);
//------MOVES FUNCTIONS -----------//
void	sa(t_list *head);
void	sb(t_list *head);
void	ss(t_list *stack_a, t_list *stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
//-----SORTING 2 -- 3 -- 4 ----//
void	sortthree(t_list **stack_a);
void	sortfour(t_list **stack_a, t_list **stack_b);
//-----CHECKER IF SORTED ALREADY-----//
int		minindex(t_list *stack_a);
int		checksorting(t_list *stack_a);
//-----ALGO-A-TO-B--//
int		ft_target(t_list *stack_a, t_list *stack_b);
void	init_tar_pos(t_list *stack_a, t_list *stack_b);
t_list	*cheap_move(t_list *stack_a, t_list *stack_b);
void	same_moves(t_list **stack_a, t_list **stack_b, t_list *cheapnode);
void	rotations_move(t_list **stack_a, t_list **stack_b, t_list *cheapnode);
//-----ALGO-B-TO-A--//
int		target_a(t_list *stack_a, t_list *stack_b);
void	init_targ(t_list *stack_a, t_list *stack_b);
void	totale_move(t_list *stack_a, t_list *stack_b);
void	sec_rotations(t_list **stack_a, t_list **stack_b, t_list *cheapnode);
//-----CALCULATE MOVES-----//
int		moves_b(t_list *stack_a, t_list *lst);
int		moves_a(t_list *stack_a, t_list *lst);
//-----FREE-----//
void	frite(t_list *stack_a);
//-----SORT A TO B -----//
void	sort_a_b(t_list **stack_a, t_list **stack_b);
//-----SORT B TO A -----//
void	sort_b_a(t_list **stack_a, t_list **stack_b);
#endif