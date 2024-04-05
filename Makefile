NAME	:= game
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42
HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBMLXA = $(LIBMLX)/build/libmlx42.a
SRCS	:= main.c map_creator.c build_objects.c key_hook.c free.c
OBJS	:= ${SRCS:.c=.o}
TSRCS = test.c
LIBFT = libft.a

all: $(LIBMLXA) $(NAME)

$(LIBMLXA):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) libft/$(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C libft

test: libmlx test.o
	@$(CC) $(CFLAGS) $(LIBS) $(HEADERS) test.o -o $(NAME)

norm:
	norminette $(SRCS)

clean:
	rm -rf $(OBJS)
	rm -f test.o
	rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
