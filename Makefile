# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maabidal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 20:08:50 by maabidal          #+#    #+#              #
#    Updated: 2022/02/17 21:30:15 by maabidal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
INC = header.h

SRCS += parsing.c
SRCS += vector_utils2.c
SRCS += vector_utils.c
#SRCS += isometric_transformation.c
SRCS += mlx_utils.c
SRCS += display.c
SRCS += matrices.c

SRCS += main.c

OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR),$(SRCS:.c=.o))

CC = gcc -g3 -fsanitize=address#-Wall -Wextra -Werror

MLX_DIR = ./mlx
MLX_LNK	= -L $(MLX_DIR) -l mlx -framework OpenGL -framework AppKit
MLX_LIB	= $(MLX_DIR)libmlx.a

LFT_DIR = ./libft/
LFT_LIB = $(LFT_DIR)libft.a
LFT_LNK = -L $(LFT_DIR) -l ft

all: $(NAME)

$(NAME) :  $(MLX_LIB) $(OBJS) $(LFT_LIB)
	$(CC) $(OBJS) $(MLX_LNK) $(LFT_LNK) -lm -o $(NAME)

$(OBJS): $(OBJS_DIR)%.o: %.c $(OBJS_DIR)
	$(CC) -I $(MLX_DIR) -I $(LFT_DIR) -c $< -o $@

$(OBJS_DIR):
	mkdir $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(LFT_LIB):
	$(MAKE) -C $(LFT_DIR)

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LFT_DIR)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(LFT_DIR)

re: fclean all

.PHONY: all clean fclean re
