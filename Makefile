NAME = cub3d
INCLUDE = includes
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O3
FSANITIZE := -fsanitize=address
LIBMLX = ./libs/minilibx-linux
LIBFT = ./libs/libft
HEADERS = -I./$(INCLUDE) -I$(LIBMLX) -I$(LIBFT)
LIBS = $(LIBFT)/libft.a $(LIBMLX)/libmlx.a -L$(LIBMLX) -lmlx -lXext -lX11 -lm
SRCS_DIR = ./srcs
SRCS = $(addprefix $(SRCS_DIR)/, main.c errors.c)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(LIBMLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(HEADERS)

%.o: %.c
	$(CC) $(CFLAGS) -c $(HEADERS) -o $@ $<

clean:
	$(MAKE) clean -C $(LIBFT)
	$(MAKE) clean -C $(LIBMLX)
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) clean -C $(LIBFT)
	rm -f $(LIBFT)/libft.a
	rm -f $(NAME)

re: fclean all
