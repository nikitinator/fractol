# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snikitin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 17:36:11 by snikitin          #+#    #+#              #
#    Updated: 2018/02/28 15:58:33 by snikitin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol     

SRC_DIR := ./srcs/
OBJ_DIR := ./obj/
INC_DIR := ./includes/
LIB_DIR := ./lib/

SRC :=	main.c\
		scrn_upd.c\
		exit_fractol.c\
		zoom_key.c\
		mov_key.c\
		toggle.c\
		change_iteration_num.c\
		iterate.c\
		validate_params.c\
		get_iter.c\
		get_pxl_clr.c\
		init_frct.c\
		print_usage.c\
		reset_frct.c\
		get_data.c\
		hooks.c
		
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

INC = $(INC_DIR)fractol.h 

LIBFT =			$(LIBFT_DIR)libft.a
LIBFT_DIR :=    $(LIB_DIR)libft/
LIBFT_INC :=    $(LIBFT_DIR)/
LIBFT_FLAGS :=  -lft -L $(LIBFT_DIR)

MLX = $(LIB_DIR)mlx/libmlx.a
MLX_DIR = $(LIB_DIR)mlx/
MLX_INC = $(LIB_DIR)mlx/
MLX_FLAGS = -lmlx -L $(MLX_INC) -framework OpenGl -framework AppKit

CC_FLAGS := -Wall -Wextra -Werror -O3 
LINK_FLAGS := $(LIBFT_FLAGS) $(MLX_FLAGS) 
HEADER_FLAGS := -I $(LIBFT_INC) -I $(MLX_DIR) -I $(INC_DIR)

CC := gcc

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ) $(INC) 
	$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean:	clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

re: fclean all

vpath %.c $(SRC_DIR)
.PHONY: all clean fclean re
