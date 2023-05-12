# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 13:38:07 by fkrug             #+#    #+#              #
#    Updated: 2023/05/12 14:37:09 by fkrug            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

CC := cc
CFLAGS := -Wall -Wextra -Werror
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = push_swap_utils_input.c push_swap.c
OBJ := $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(SRC) $(OBJ)
	$(CC) $(CFLAGS) push_swap.c push_swap_utils_input.c -L$(LIBFT_DIR) -lft -o $(NAME)
#	ar rcs $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	/bin/rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all clean
	clear

.PHONY: all clean fclean re