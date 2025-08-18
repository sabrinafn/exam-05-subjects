NAME := game_of_life
CC := cc
FLAGS := -Wall -Wextra -Werror -g3

SRC := src/game_of_life.c
OBJ := $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

v: all
	echo 'dxss' | valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 3 3 1 | cat -e
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re v