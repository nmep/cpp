NAME = DiamondTrap

SRC =	./ClapTrap.cpp\
		./FragTrap.cpp\
		./main.cpp\
		./ScavTrap.cpp\
		./DiamondTrap.cpp


OBJ = $(SRC:.cpp=.o)
DEP_FILES = $(OBJ:.o=.d)

header =	./ClapTrap.hpp\
			./FragTrap.hpp\
			./ScavTrap.hpp\
			./DiamondTrap.hpp

CC = g++

flags = -Wall -Wextra -Werror -std=c++98 -MMD -MP -g3

all: $(NAME)

%.o: %.cpp
	$(CC) $(flags) -c $< -o $(<:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(flags) $(OBJ) -o $@

clean:
	rm -f $(OBJ) $(DEP_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: 
	echo src $(SRC)
	echo obj$(OBJ)

-include $(DEP_FILES)