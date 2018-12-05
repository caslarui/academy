# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cion <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 18:08:29 by cion              #+#    #+#              #
#    Updated: 2017/12/22 14:09:36 by cion             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
CFLAGS = -Wall -Wextra -Werror
INC_DIR = includes/
SRC = *.c
OBJ = *.o
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)

$(OBJ):
		@$(CC) -c $(CFLAGD) $(SRC) -I$(INC_DIR) 

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all
