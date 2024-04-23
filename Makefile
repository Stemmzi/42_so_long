NAME	= so_long
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX = ./MLX42
HEADERS	= -I $(LIBMLX)/include
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBMLXA = $(LIBMLX)/build/libmlx42.a
SRCS = main.c map_creator.c image_creator.c key_hook.c free.c map_checker.c game_logic.c path_finder.c path_finder_utils.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all: $(LIBMLXA) $(NAME)

$(LIBMLXA): $(LIBMLX)
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBMLX):
	git clone https://github.com/codam-coding-college/MLX42.git
	cmake $(LIBMLX) -B $(LIBMLX)/build
	cmake --build $(LIBMLX)/build -j4 

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LIBFT) -g -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(LIBFT):
	make -C libft

norm:
	norminette $(SRCS)
	norminette $(NAME).h

clean:
	rm -f $(OBJS)
	rm -rf $(LIBMLX)/build
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all, norm, clean, fclean, re
