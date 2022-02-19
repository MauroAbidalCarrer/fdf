# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maabidal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 20:08:50 by maabidal          #+#    #+#              #
#    Updated: 2022/02/19 22:16:09 by maabidal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
INC = header.h

SRCS += parsing.c
SRCS += vector_utils2.c
SRCS += vector_utils.c
SRCS += mlx_utils.c
SRCS += display.c
SRCS += matrices.c
SRCS += utils.c
SRCS += hooks.c

SRCS += main.c

OBJS_DIR = obj/
OBJS_DIR_BONUS = obj/
OBJS = $(addprefix $(OBJS_DIR),$(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJS_DIR_BONUS), $(SRCS:.c=.o))

CC = gcc -Wall -Wextra -Werror

MLX_DIR = ./mlx
MLX_LNK	= -L $(MLX_DIR) -l mlx -framework OpenGL -framework AppKit
MLX_LIB	= $(MLX_DIR)libmlx.a

LFT_DIR = ./libft/
LFT_LIB = $(LFT_DIR)libft.a
LFT_LNK = -L $(LFT_DIR) -l ft

all: $(NAME)

$(NAME) :  $(MLX_LIB) $(OBJS) $(LFT_LIB)
	$(CC) $(OBJS) $(MLX_LNK) $(LFT_LNK) -lm -o $(NAME)

bonus :  $(MLX_LIB) $(OBJS_BONUS) $(LFT_LIB)
	$(CC) $(OBJS_BONUS) $(MLX_LNK) $(LFT_LNK) -lm -o fdf_bonus

$(OBJS_BONUS): $(OBJS_DIR_BONUS)%.o: %.c $(OBJS_DIR_BONUS)
	$(CC) -D BONUS=1 -I $(MLX_DIR) -I $(LFT_DIR) -c $< -o $@

$(OBJS): $(OBJS_DIR)%.o: %.c $(OBJS_DIR)
	$(CC) -D BONUS=1  -I $(MLX_DIR) -I $(LFT_DIR) -c $< -o $@

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
