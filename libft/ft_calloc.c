/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:12:22 by ychedmi           #+#    #+#             */
/*   Updated: 2024/11/20 23:51:44 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*p;

	if (size != 0 && (count * size) / size != count)
		return (NULL);
	i = 0;
	p = malloc(count * (size));
	if (!p)
		return (NULL);
	while (i < (count * size))
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}
