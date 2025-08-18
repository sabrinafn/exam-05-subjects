NAME	:= vect2

CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -g3 -std=c++98

SRC_DIR	:= src
OBJ_DIR	:= obj
MAIN	:= subject/main.cpp

SRC_CPP	:= $(wildcard $(SRC_DIR)/*.cpp)
OBJ_SRC	:= $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_CPP))
OBJ_MAIN := $(OBJ_DIR)/main.o

OFILES	:= $(OBJ_MAIN) $(OBJ_SRC)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I$(SRC_DIR) -c $< -o $@

$(OBJ_MAIN): $(MAIN)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I$(SRC_DIR) -c $< -o $@

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
