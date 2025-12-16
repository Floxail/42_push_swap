# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: floxail <floxail@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 10:18:30 by floxail           #+#    #+#              #
#    Updated: 2025/12/16 10:42:44 by floxail          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/push_swap.c \
	   utils/chained_lst.c \
	   utils/convert.c \
	   utils/ft_check.c \
	   utils/utils.c \
	   operation/push.c \
	   operation/swap.c \
	   operation/rotate.c \
	   operation/reverse_rotate.c \
	   sort/sort_three.c \
	   sort/sort_five.c \
	   sort/quick_sort.c \
	   sort/quick_sort_utils.c

OBJS = $(SRCS:.c=.o)

LIBFT = utils/libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -Lutils/libft -lft -o $(NAME)

# Compilation de la libft
$(LIBFT):
	@make -C utils/libft

# Règle pour les objets (.c -> .o)
%.o: %.c
	@$(CC) $(CFLAGS) -I. -Iutils/libft -c $< -o $@
	@echo "Compiled"
	   
clean:
	@rm -f $(OBJS)
	@make -C utils/libft clean
	@echo "Cleaned object files"

fclean: clean
	@rm -f $(NAME)
	@make -C utils/libft fclean
	@echo "Fully cleaned"

re: fclean all

.PHONY: all clean fclean re