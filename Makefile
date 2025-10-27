# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 11:54:19 by leramos-          #+#    #+#              #
#    Updated: 2025/10/27 11:40:07 by leramos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project structure
NAME = so_long
SRCS_DIR = src
INCS_DIR = includes

# Libft structure
LIBFT_DIR = libft
LIBFT_SRCS_DIR = $(LIBFT_DIR)/src
LIBFT_INCS_DIR = $(LIBFT_DIR)/includes

# Minilibx structure
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_DEPENDENCIES = -lXext -lX11 -lm

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCS_DIR) -I$(LIBFT_INCS_DIR) -I$(MLX_DIR)
AR = ar rcs
RM = rm -f

# Files
FILES = main utils forms hooks exit map_validation map #colors colors_utils
LIBFT_LIB = $(LIBFT_DIR)/libft.a
OUT_FILE = so_long.out

SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))
OBJS = $(SRCS:.c=.o)

# Rules
all: $(NAME)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
# $(CC) $(CFLAGS) $^ -o $(OUT_FILE)
	$(CC) $(CFLAGS) $^ -L$(MLX_DIR) $(MLX_DEPENDENCIES) -o $(OUT_FILE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
# Add -03 or -02 and maybe -I/usr/include

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLX_DIR) clean
	$(RM) $(NAME)

re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re