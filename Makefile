NAME = cub3d
INCLUDE = include
LIB = lib
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBMLX = ./$(LIB)/MLX42
LIBFT = ./$(LIB)/libft

HEADERS = -I./$(INCLUDE) -I$(LIBMLX)/$(INCLUDE) -I$(LIBFT)
LIBS = $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -L$(LIBMLX)

SRCS_DIR = ./srcs
RENDER_DIR = $(SRCS_DIR)/render
SRCS = $(addprefix $(RENDER_DIR)/, main.c hook.c map.c player.c graphic.c ray.c ray_intersection.c ray_utils.c utils.c) \
		$(addprefix $(RENDER_DIR)/draw/, draw.c rect.c line.c circle.c color.c)
OBJS = $(SRCS:.c=.o)

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	OS_FLAGS = -ldl -lglfw -pthread -lm
endif
ifeq ($(UNAME), Darwin)
	OS_FLAGS = -lglfw -framework Cocoa -framework OpenGL -framework IOKit
endif

all : libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && $(MAKE) -C $(LIBMLX)/build -j4

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(OS_FLAGS) $(HEADERS)

%.o: %.c
	$(CC) $(CFLAGS) -c $(HEADERS) -o $@ $<

clean:
	$(MAKE) clean -C $(LIBFT)
	@rm -rf $(OBJS)

fclean: clean
	$(MAKE) clean -C $(LIBFT)
	@rm -f $(LIBFT)/libft.a
	@rm -rf $(LIBMLX)/build
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx
