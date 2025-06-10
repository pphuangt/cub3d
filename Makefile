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
PARSE_DIR = $(SRCS_DIR)/parse
SRCS = $(addprefix $(RENDER_DIR)/, main.c hook.c map.c player.c graphic.c\
			ray.c ray_horizontal.c ray_vertical.c ray_utils.c wall.c utils.c) \
		$(addprefix $(RENDER_DIR)/draw/, draw.c rect.c line.c circle.c color.c) \
		$(addprefix $(PARSE_DIR)/, check_around.c check_map.c\
			convert_color_to_int.c load_map.c map_info.c name_check.c parse.c\
			parse_color_str.c parse_utils.c texture.c)
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

fclean:
	$(MAKE) clean -C $(LIBFT)
	@rm -rf $(OBJS)
	@rm -f $(LIBFT)/libft.a
	@rm -rf $(LIBMLX)/build
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx
