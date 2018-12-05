# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user00 <user00@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 15:01:53 by cion              #+#    #+#              #
#    Updated: 2018/03/14 16:45:03 by user00           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME = fractal


cc = gcc
C_FLAGS = -Wall -Werror -Wextra -g
FRAM = -L minilibx -I minilibx -lmlx -framework OpenGL -framework AppKit -g
# FRAM = -framework OpenGL -framework AppKit minilibx/libmlx.a


OBJ_PATH = ./objects/
LIBFT_PATH = ./libft/
INCLUDES_PATH = ./includes/
SOURCES_PATH = ./sources/

SOURCES_NAME = main_f.c adjustments.c mandelbrot.c mouse.c julia.c colors.c \
				colors2.c keyboard.c newton.c
OBJ_NAME = $(SOURCES_NAME:.c=.o)
INC_NAME = fractal.h

SRC = $(addprefix $(SOURCES_PATH),$(SOURCES_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INCLUDES_PATH))

all: $(NAME)

$(NAME): $(OBJ) 
		@make -C $(LIBFT_PATH)
		@$(CC) -o $(NAME) $(FRAM) -L $(LIBFT_PATH) -lft $^ -o $@

$(OBJ_PATH)%.o: $(SOURCES_PATH)%.c
		@mkdir -p $(OBJ_PATH) 2> /dev/null || true
		@$(CC) $(C_FLAGS) $(INC) -o $@ -c $<

clean:
		@make -C $(LIBFT_PATH) clean
		@rm -rf $(OBJ_PATH)

fclean: clean
		@make -C $(LIBFT_PATH) fclean
		@rm -f $(NAME)
 
re: fclean all
