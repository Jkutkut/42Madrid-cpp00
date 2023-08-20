CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

BIN = bin

NAME = megaphone

SRCS = megaphone.cpp

OBJS = $(SRCS:%.cpp=${BIN}/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Generating $@\c"
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo " [\033[32mOK\033[0m]"

${BIN}:
	mkdir -p ${BIN}

${BIN}/%.o: %.cpp ${BIN}
	@echo "[Compiling] $< -> $@\c"
	@$(CC) $(FLAGS) -c $< -o $@
	@echo " [\033[32mOK\033[0m]"

clean:
	@echo "\033[1;31mCleaning\033[0m objects\c"
	@rm -rf $(BIN)
	@echo " [\033[32mOK\033[0m]"

fclean: clean
	@echo "\033[1;31mCleaning\033[0m $(NAME)\c"
	@rm -f $(NAME)
	@echo " [\033[32mOK\033[0m]"

re: fclean all
