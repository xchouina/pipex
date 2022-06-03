SRCS =	push_swap.c			\
		partitions.c		\
		op_swap.c			\
		op_push.c			\
		op_rotate.c			\
		op_reverse_rotate.c	\
		algorithm.c			\
		algorithm_utils.c	\
		algorithm_index.c	\
		algo_three.c		\
		algo_hundred_1.c	\
		algo_hundred_2.c	\

LIBS =	../libft/libft.a 			\
		../ft_printf/ft_printf.a	\

NAME = push_swap

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Werror -Wall -Wextra -g

.c.o : 
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ $(CC) $(CFLAGS)  $(OBJS) $(LIBS) -o $(NAME) 
	@echo "PUSH_SWAP	| STATUS: \033[0;32mOK\033[0;00m"

all: $(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "PUSH_SWAP	| STATUS: \033[0;36mCLEANED\033[0;00m"

fclean: clean
	@rm -f $(NAME)

re: fclean all
