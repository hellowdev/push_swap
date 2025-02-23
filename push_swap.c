/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:14:30 by ychedmi           #+#    #+#             */
/*   Updated: 2025/02/23 15:22:19 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort(t_list **stack_a, t_list **stack_b)
{
	if (checksorting(*stack_a) == 0 && (ft_lstsize(*stack_a) == 3 \
	|| ft_lstsize(*stack_a) == 2))
		sortthree(stack_a);
	else if (checksorting(*stack_a) == 0 && ft_lstsize(*stack_a) == 4)
		sortfour(stack_a, stack_b);
	else if (checksorting(*stack_a) == 0 && ft_lstsize(*stack_a) > 4)
	{
		sort_a_b(stack_a, stack_b);
		sort_b_a(stack_a, stack_b);
	}
}

void	frite(t_list *stack_a)
{
	while (stack_a)
	{
		free(stack_a);
		stack_a = stack_a->next;
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
	sort(&stack_a, &stack_b);
	frite(stack_a);
}
