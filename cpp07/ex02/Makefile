NAME = Array

SRC = main.cpp
	
OBJ = $(addprefix ./obj/, $(notdir $(SRC:.cpp=.o)))
DEP_FILES = $(addprefix ./dep/, $(notdir $(OBJ:.o=.d)))

header = $(shell find ./ -name "*.hpp")

CC = c++

OBJDIR= ./obj/

flags = -Wall -Wextra -Werror -std=c++98 -MMD -MP -g3 -ftrapv



all: $(NAME)

./obj/%.o: %.cpp | create_dir
	$(CC) $(flags) -c $< -o $@ -MF ./dep/$(<:.cpp=.d) 
	@echo dep file $(<:.cpp=.d)

$(NAME): $(OBJ)
	$(CC) $(flags) $(OBJ) -o $@

clean:
	rm -f $(OBJ) $(DEP_FILES)
	rm -rf dep obj

fclean: clean
	rm -f $(NAME)

re: fclean all

create_dir:
	$(shell mkdir -p obj dep)

test: 
	@echo src $(SRC)
	@echo
	@echo
	@echo obj $(OBJ)
	@echo
	@echo
	@echo dep $(DEP_FILES)

-include $(DEP_FILES)

.PHONY: all clean fclean re