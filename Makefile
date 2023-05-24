# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 13:38:07 by fkrug             #+#    #+#              #
#    Updated: 2023/05/24 21:28:33 by fkrug            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

CC := cc
#CFLAGS := -Wall -Wextra -Werror -fsanitize=address -g
CFLAGS := -Wall -Wextra -fsanitize=address -g
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_PSWAP = push_swap.c push_swap_utils_operations.c \
			push_swap_utils_operations2.c
SRC_UTILS = push_swap_utils_input.c push_swap_utils_input2.c \
	 		push_swap_utils_algo.c push_swap_utils_algo2.c \
			push_swap_utils_algo3.c push_swap_utils_algo5.c
SRC = $(SRC_PSWAP) $(SRC_UTILS)
OBJ := $(SRC:.c=.o)

BON_NAME = checker
BON_DIR = bonus/
BON_SRC = 	checker.c push_swap_utils_operations_bonus.c \
			 push_swap_utils_operations2_bonus.c
BON_FILE = $(addprefix $(BON_DIR),$(BON_SRC))
SRC_BON = $(BON_FILE) $(SRC_UTILS)
BON_OBJ := $(BON_FILE:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

#$(NAME): $(SRC) $(OBJ)
$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(BON_FILE)
	$(CC) $(CFLAGS) $(SRC_BON) -L$(LIBFT_DIR) -lft -o $(BON_NAME)

clean:
	/bin/rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	/bin/rm -f $(NAME) $(BON_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all clean
	clear

.PHONY: all clean fclean re bonus