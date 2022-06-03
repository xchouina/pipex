SRCS = 	ft_printf.c \
		ft_printf_c-s.c \
		ft_printf_d-i-u.c \
		ft_printf_x-X.c \
		ft_printf_p.c \

NAME = ft_printf.a

OBJS = $(SRCS:.c=.o)

CC = gcc

CC_FLAGS = -Werror -Wall -Wextra

.c.o :
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "FT_PRINTF	| STATUS: \033[0;32mOK\033[0;00m"

all: $(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "FT_PRINTF	| STATUS: \033[0;36mCLEANED\033[0;00m"

fclean: clean
	@rm -f $(NAME)

re: fclean all
