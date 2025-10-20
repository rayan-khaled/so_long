# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 13:42:42 by rakhaled          #+#    #+#              #
#    Updated: 2025/10/04 16:30:51 by rakhaled         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := so_long
CC          := cc
CFLAGS      := -Wall -Wextra -Werror

SRCS := main.c check_elements.c check_path.c check_walls.c \
		draw_mlx.c exit.c extensions.c free.c init_mlx.c map.c \
		movement.c utils.c validate_map.c read.c \
		get_next_line.c get_next_line_utils.c

OBJS := $(SRCS:.c=.o)

MLX_DIR     = ./minilibx-linux
MLX_INC     = -I$(MLX_DIR)
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_LNK     = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_INC) $(MLX_LNK) -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re