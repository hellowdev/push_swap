CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC = push_swap.c	check_errors.c		moves.c		minsort.c
LIBFT_DIR = ./libft
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_DIR)/libft.a

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)
	make -C ./libft clean

fclean : clean
	rm -rf $(NAME)
	make -C ./libft fclean

re : fclean all