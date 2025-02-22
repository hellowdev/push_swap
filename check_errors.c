/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:28:19 by ychedmi           #+#    #+#             */
/*   Updated: 2025/02/22 12:35:27 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkdb(t_list *look)
{
	t_list	*look2;
	t_list	*look3;

	look3 = look;
	look2 = look3->next;
	if (look->content > INT_MAX || look->content < INT_MIN)
		return (1);
	while (look3)
	{
		look2 = look3->next;
		while (look2)
		{
			if ((look3->content == look2->content) || (look3->content > INT_MAX \
			|| look3->content < INT_MIN))
				return (1);
			look2 = look2->next;
		}
		look3 = look3->next;
	}
	return (0);
}

int	checksp(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32)
	{
		if (str[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	checkdig(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i])
	{
		if (((ft_isdigit(str[i]) == 0 && str[i] != 32 && \
		str[i] != '-' && str[i] != '+') \
		|| (str[i] == '+' && ft_isdigit(str[i + 1]) == 0) \
		|| (str[i] == '-' && ft_isdigit(str[i + 1]) == 0)) \
		|| (ft_isdigit(str[i]) == 1 && str[i + 1] == '-' ) \
		|| (ft_isdigit(str[i]) == 1 && str[i + 1] == '+' ))
			return (1);
		i++;
	}
	return (0);
}
