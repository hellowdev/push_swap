CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = checker

SRC = check_sort_bonus.c	checker_bonus.c	mv_bonus.c	mvv_bonus.c	myv_bonus.c\
		./utils_bonus/ft_calloc_bonus.c		./utils_bonus/ft_atoi_bonus.c	./utils_bonus/ft_isdigit_bonus.c\
		./utils_bonus/ft_split_bonus.c		./utils_bonus/ft_memcpy_bonus.c\
		./utils_bonus/ft_lstadd_back_bonus.c	./utils_bonus/ft_lstnew_bonus.c\
		./utils_bonus/ft_lstlast_bonus.c 	./utils_bonus/ft_lstadd_front_bonus.c		./utils_bonus/ft_lstsize_bonus.c \
		check_errors_bonus.c	./get_next_line_bonus/get_next_line_bonus.c		./get_next_line_bonus/get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.c  checker_bonus.h  ./utils_bonus/libft_bonus.h	./get_next_line_bonus/get_next_line_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all