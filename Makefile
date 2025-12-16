# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: floxail <floxail@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 10:18:30 by floxail           #+#    #+#              #
#    Updated: 2025/12/16 10:18:32 by floxail          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Liste explicite des fichiers avec leur chemin
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

# Chemin vers la libft
LIBFT = utils/libft/libft.a

all: $(NAME)

# Compilation de l'executable
# -I. permet de trouver push_swap.h à la racine
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -Lutils/libft -lft -o $(NAME)

# Compilation de la libft
$(LIBFT):
	make -C utils/libft

# Règle pour les objets (.c -> .o)
%.o: %.c
	$(CC) $(CFLAGS) -I. -Iutils/libft -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C utils/libft clean

fclean: clean
	rm -f $(NAME)
	make -C utils/libft fclean

re: fclean all

.PHONY: all clean fclean re