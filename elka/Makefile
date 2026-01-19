NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = sources
OBJ_DIR = objects
SRCS = complex_sort.c ft_split.c indexing.c main.c medium_sort2.c medium_sort.c medium_sort_utils.c parsing.c \
parsing_utils.c print_error.c push_swap.c push_swap_utils2.c push_swap_utils.c simple_sort.c
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
HEADERS = $(SRC_DIR)/push_swap.h

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






