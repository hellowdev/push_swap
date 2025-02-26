/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:51:36 by ychedmi           #+#    #+#             */
/*   Updated: 2025/02/26 18:24:39 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	long			content;
	int				tar_index;
	int				position;
	int				moves;
	struct s_list	*next;
}		t_list;

int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(long content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_isdigit(int c);
long	ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
#endif