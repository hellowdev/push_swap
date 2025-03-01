/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:47:50 by ychedmi           #+#    #+#             */
/*   Updated: 2025/03/01 20:36:02 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "get_next_line_bonus/get_next_line_bonus.h"

void	freesp(char **b)
{
	int	i;

	i = 0;
	while (b[i])
	{
		free(b[i]);
		i++;
	}
	free(b);
}

int	retatoi(char *p, t_list **stack_a)
{
	char	**b;
	int		i;
	t_list	*new;

	i = 0;
	b = ft_split(p, 32);
	while (b[i])
	{
		new = ft_lstnew(ft_atoi(b[i]));
		if (!new)
			return (frite(*stack_a), 0);
		if (new->content > INT_MAX || new->content < INT_MIN)
			return (frite(*stack_a), freesp(b), free(new), 1);
		ft_lstadd_back(stack_a, new);
		i++;
	}
	freesp(b);
	return (0);
}

int	mv(t_list **stack_a, t_list **stack_b, char *move)
{
	if (ft_strcmp(move, "sa\n") == 0)
		sa(*stack_a);
	else if (ft_strcmp(move, "sb\n") == 0)
		sb(*stack_b);
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
			frite(*stack_a);
			frite(*stack_b);
			free(move);
			get_next_line(-1);
			exit(1);
		}
		free(move);
	}
}

int	main(int ac, char *av[])
{
	int		i;
	int		r;
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
			r = retatoi(av[i], &stack_a);
		if (r == 1)
			return (1);
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
