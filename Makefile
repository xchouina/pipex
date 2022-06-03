# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 10:43:11 by xchouina          #+#    #+#              #
#    Updated: 2022/06/01 09:14:29 by xchouina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	pipex.c			\
		pipex_utils1.c	\

NAME = pipex

OBJS = $(SRCS:.c=.o)

CC= gcc

CFLAGS = -Werror -Wextra -Wall -g

# LIBRARIES
LIBS =	big_boi/libft/libft.a			\
		big_boi/ft_printf/ft_printf.a	\
		# big_boi/push_swap/push_swap.a	\


## CD

CD_BB = cd big_boi && make
RM_BB = cd big_boi && make fclean


.c.o :
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@$(CD_BB)
	@ $(CC) $(CFLAGS)  $(OBJS) $(LIBS) -o $(NAME) 
	@echo "PIPEX		| STATUS: \033[0;32mOK\033[0;00m"
	@echo "---------------------------------------------"

all: $(NAME)

clean:
	@rm -rf $(OBJS)	
	@$(RM_BB)
	@echo "PIPEX		| STATUS: \033[0;36mCLEANED\033[0;00m"

fclean: clean
	@rm -f $(NAME)

re: fclean all