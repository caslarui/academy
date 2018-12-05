# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user00 <user00@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/08 17:55:51 by user00            #+#    #+#              #
#    Updated: 2018/05/11 17:19:57 by user00           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
CFLAGS = -Wall -Wextra -Werror
INC_DIR = includes/
SRC = *.c
VEC = vector/*.c
OBJ = *.o
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)

$(OBJ):
		@$(CC) -c $(CFLAGD) $(SRC) $(VEC) -I$(INC_DIR) 

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all