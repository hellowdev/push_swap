CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = checker

SRC = check_sort.c	checker.c	mv.c	mvv.c	myv.c\
		../libft/ft_calloc.c		../libft/ft_atoi.c	../libft/ft_isdigit.c\
		../libft/ft_split.c		../libft/ft_memcpy.c\
		../libft/ft_lstadd_back_bonus.c	../libft/ft_lstnew.c\
		../libft/ft_lstlast_bonus.c 	../libft/ft_lstadd_front_bonus.c		../libft/ft_lstsize.c \
		../check_errors.c	./get_next_line/get_next_line.c		./get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.c  checker.h  ../libft/libft.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all