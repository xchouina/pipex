NAME = big_boi

# OBJS = $(SRCS:.c=.o)

CC= gcc

CC_FLAGS = -Werror -Wextra -Wall

# LIBRARIES


## CD

CD_LIBFT = cd libft && make
RM_LIBFT = cd libft && make fclean

CD_FT_PRINTF = cd ft_printf && make
RM_FT_PRINTF = cd ft_printf && make fclean

CD_PUSH_SWAP = cd push_swap && make
RM_PUSH_SWAP = cd push_swap && make fclean

.c.o :
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CD_LIBFT)
	@$(CD_FT_PRINTF)
	@$(CD_PUSH_SWAP)
	@echo "BIG_BOI		| STATUS: \033[0;32mREADY\033[0;00m"

all: $(NAME)

clean:
	@rm -rf $(OBJS)	
	@$(RM_LIBFT)
	@$(RM_FT_PRINTF)
	@$(RM_PUSH_SWAP)
	@echo "BIG_BOI		| STATUS: \033[0;36mCLEANED\033[0;00m"

fclean: clean
	@rm -f $(NAME)

re: fclean all