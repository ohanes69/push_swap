NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = sources
OBJ_DIR = objects

SRCS =	bench.c \
		ft_split.c \
		libft_utils.c \
		parsing.c \
		push_swap.c \
		push_swap_utils2.c \
		sort_complex.c \
		sort_medium.c \
		sort_simple.c \
		ft_printf.c \
		indexing.c \
		main.c \
		parsing_utils.c \
		push_swap_utils.c \
		sort_medium2.c \
		sort_medium_utils.c

HEADERS = $(SRC_DIR)/push_swap.h

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re






