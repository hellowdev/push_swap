CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = ft_calloc.c	ft_atoi.c	ft_isdigit.c    ft_strjoin.c 	ft_split.c		ft_memcpy.c \
ft_lstadd_back_bonus.c	ft_lstnew.c		ft_lstlast_bonus.c ft_lstadd_front_bonus.c		ft_lstsize.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean