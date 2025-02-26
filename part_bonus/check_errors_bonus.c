/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:31:44 by ychedmi           #+#    #+#             */
/*   Updated: 2025/02/26 22:04:56 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	checkdb(t_list *look)
{
	t_list	*head;

	head = look;
	while (head)
	{
		look = head->next;
		while (look)
		{
			if (head->content == look->content)
				return (1);
			look = look->next;
		}
		head = head->next;
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
