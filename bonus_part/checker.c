/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:47:50 by ychedmi           #+#    #+#             */
/*   Updated: 2025/02/23 15:23:22 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../push_swap.h"
#include "get_next_linee/get_next_line.h"

void	retatoi(char *p, t_list **stack_a)
{
	char	**b;
	int		i;
	t_list	*new;

	i = 0;
	b = ft_split(p, 32);
	while (b[i])
	{
		new = ft_lstnew(ft_atoi(b[i]));
		ft_lstadd_back(stack_a, new);
		if (!new)
		{
			frite(*stack_a);
			return ;
		}
		i++;
	}
	i = 0;
	while (b[i])
	{
		free(b[i]);
		i++;
	}
	free(b);
}

void	frite(t_list *stack_a)
{
	while (stack_a)
	{
		free(stack_a);
		stack_a = stack_a->next;
	}
}

int	mv(t_list **stack_a, t_list **stack_b, char *move)
{
	if (ft_strcmp(move, "sa\n") == 0)
		sa(*stack_a);
	else if (ft_strcmp(move, "sb\n") == 0)
		sb(*stack_a);
	else if (ft_strcmp(move, "ss\n") == 0)
		ss(*stack_a, *stack_b);
	else if (ft_strcmp(move, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(move, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(move, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(move, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(move, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(move, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(move, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(move, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	checker(t_list **stack_a, t_list **stack_b)
{
	char	*move;

	move = "";
	while (move)
	{
		move = get_next_line(0);
		if (!move)
			break ;
		else if (!mv(stack_a, stack_b, move))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		free(move);
	}
}

int	main(int ac, char *av[])
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	i = 0;
	while (++i < ac)
	{
		if (checkdig(av[i]) == 1 || checksp(av[i]) == 1)
			return (frite(stack_a), write(2, "Error\n", 6), 1);
		else
			retatoi(av[i], &stack_a);
	}
	if (!stack_a)
		return (0);
	if (checkdb(stack_a) == 1)
		return (frite(stack_a), write(2, "Error\n", 6), 1);
	checker(&stack_a, &stack_b);
	srt(stack_a, stack_b);
	frite(stack_a);
	frite(stack_b);
}
