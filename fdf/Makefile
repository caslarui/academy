# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cion <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 15:01:53 by cion              #+#    #+#              #
#    Updated: 2018/01/09 17:54:08 by cion             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME = fdf


cc = gcc
C_FLAGS = -Wall -Werror -Wextra -g
FRAM = -L minilibx -I minilibx -lmlx -framework OpenGL -framework AppKit -g
# FRAM = -framework OpenGL -framework AppKit minilibx/libmlx.a


OBJ_PATH = ./objects/
LIBFT_PATH = ./libft/
INCLUDES_PATH = ./includes/
SOURCES_PATH = ./sources/

SOURCES_NAME = calculus.c color.c drawing.c events.c fdf.c projection.c rotation.c error.c
OBJ_NAME = $(SOURCES_NAME:.c=.o)
INC_NAME = fdf.h

SRC = $(addprefix $(SOURCES_PATH),$(SOURCES_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INCLUDES_PATH))

all: $(NAME)

$(NAME): $(OBJ) 
		@make -C $(LIBFT_PATH)
		@$(CC) -o $(NAME) $(FRAM) -L $(LIBFT_PATH) -lft $^ -o $@
		@norminette $(SOURCES_PATH) $(INCLUDES_PATH)

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
