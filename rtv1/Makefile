NAME = rtv1

SRC_PATH = sources

SRC_NAME =	camera.c\
			color.c\
			draw.c\
			events.c\
			light.c\
			rtv1.c\
			object_cone.c\
			object_cylinder.c\
			object_plane.c\
			object_sphere.c\
			object.c\
			parse_c.c\
			parse_l.c\
			parse_o.c\
			parse_s.c\
			parser_toolbox.c\
			scene.c\
			vector_op1.c \
			vector_op2.c 

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = ./objs
INC_PATH = ./includes
LFT_PATH = ./libft
MLX_PATH =

CC = gcc -g
CFLAGS = -Werror -Wextra -Wall
LDFLAGS = -L$(LFT_PATH)
LDLIBS = -lft -lmlx -lm -lpthread

UNAME := $(shell uname)

ifeq ($(UNAME),Darwin)
	MLX_PATH += ./minilibx/osx
	LDFLAGS += -L$(MLX_PATH)
	LDLIBS += -framework AppKit -framework OpenGL
endif

ifeq ($(UNAME),Linux)
	MLX_PATH += ./minilibx/linux
	LDFLAGS += -L$(MLX_PATH)
	LDLIBS += -lX11 -lXext
endif

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LFT_PATH)
	-make -C $(MLX_PATH)
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $< -I$(INC_PATH) -I$(LFT_PATH) -I$(MLX_PATH)

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	make -C $(LFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -fv $(NAME)
	make -C $(LFT_PATH) fclean
	make -C $(MLX_PATH) clean

re:	fclean all
