NAME    := polyset
CC      := c++
FLAGS   := -Wall -Wextra -Werror -g3 -std=c++98

SRC_DIR := ./src
SUBJ_DIR := ./subject
OBJ_DIR := ./obj

SRC_CPP := $(wildcard $(SRC_DIR)/*.cpp)
SUBJ_CPP := $(wildcard $(SUBJ_DIR)/*.cpp)

SRC_OBJ := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/src_%.o,$(SRC_CPP))
SUBJ_OBJ := $(patsubst $(SUBJ_DIR)/%.cpp,$(OBJ_DIR)/subj_%.o,$(SUBJ_CPP))

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/src_%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(FLAGS) -I$(SRC_DIR) -I$(SUBJ_DIR) -c $< -o $@

$(OBJ_DIR)/subj_%.o: $(SUBJ_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(FLAGS) -I$(SRC_DIR) -I$(SUBJ_DIR) -c $< -o $@

$(NAME): $(SRC_OBJ) $(SUBJ_OBJ)
	$(CC) $(FLAGS) $(SRC_OBJ) $(SUBJ_OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
