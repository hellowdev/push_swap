/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:56:16 by ychedmi           #+#    #+#             */
/*   Updated: 2025/02/22 13:42:20 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	size_t			i;
	int				sign;
	unsigned long	r;

	sign = 1;
	r = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		if ((r > __LONG_MAX__ && sign == -1) || (r > __LONG_MAX__ && sign == 1))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return ((long)(sign * r));
}
