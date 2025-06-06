NAME = cub3d
INCLUDE = include
LIB = lib
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBMLX = ./$(LIB)/MLX42
LIBFT = ./$(LIB)/libft
PRINTF = ./$(LIB)/ft_printf
GNL = ./$(LIB)/get_next_line

HEADERS = -I./$(INCLUDE) -I$(LIBMLX)/$(INCLUDE) -I$(LIBFT) -I$(PRINTF) -I$(GNL)
LIBS = $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -L$(LIBMLX) 

SRCS =	./srcs/main.c \
		./srcs/hook.c \
		./srcs/utils.c \
		./srcs/map.c \
		./srcs/player.c \
		./srcs/parse/check_around.c \
		./srcs/parse/check_map.c \
		./srcs/parse/convert_color_to_int.c \
		./srcs/parse/load_map.c \
		./srcs/parse/map_info.c \
		./srcs/parse/name_check.c \
		./srcs/parse/parse_color_str.c \
		./srcs/parse/parse_utils.c \
		./srcs/parse/parse.c \
		./srcs/parse/texture.c
OBJS_DIR = objs
OBJS = $(SRCS:./%.c=$(OBJS_DIR)/%.o)

$(OBJS_DIR)/%.o: ./%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $(HEADERS) $< -o $@

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	OS_FLAGS = -ldl -lglfw -pthread -lm
endif

# ----Original version----
# ifeq ($(UNAME), Darwin)
# 	OS_FLAGS = -lglfw -framework Cocoa -framework OpenGL -framework IOKit

# --Hong Macbook version--
ifeq ($(UNAME), Darwin)
	OS_FLAGS = -L/usr/local/Cellar/glfw/3.4/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit
endif

all : libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && $(MAKE) -C $(LIBMLX)/build -j4

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(OS_FLAGS) $(HEADERS)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $(HEADERS) -o $@ $<

clean:
	$(MAKE) clean -C $(LIBFT)
	@rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) clean -C $(LIBFT)
	@rm -f $(LIBFT)/libft.a
	@rm -rf $(LIBMLX)/build
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx
