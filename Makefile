CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
SRC = 	./libft/ft_calloc.c		./libft/ft_atoi.c	./libft/ft_isdigit.c\
		./libft/ft_split.c		./libft/ft_memcpy.c\
		./libft/ft_lstadd_back_bonus.c	./libft/ft_lstnew.c\
		./libft/ft_lstlast_bonus.c 	./libft/ft_lstadd_front_bonus.c		./libft/ft_lstsize.c \
		minsort.c	movesone.c	movestwo.c	check_errors.c	push_swap.c\
		movesthree.c	./algo/calculate.c	./algo/cheap_a_b.c		./algo/cheap_b_a.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.c push_swap.h ./libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all