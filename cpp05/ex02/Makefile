NAME = No,YouNeedForm28B,Not28C

SRC =	./Bureaucrat.cpp\
		./AForm.cpp\
		./main.cpp\
		./ShrubberyCreationForm.cpp\
		./RobotomyRequestForm.cpp\
		./PresedientialPardonForm.cpp


OBJ = $(SRC:.cpp=.o)
DEP_FILES = $(OBJ:.o=.d)

header = ./Bureaucrat.hpp\
		./AForm.hpp\
		./ShrubberyCreationForm.hpp\
		./RobotomyRequestForm.hpp\
		./PresidentialPardonForm.hpp

CC = g++

flags = -Wall -Wextra -Werror -std=c++98 -MMD -MP -g3 #-ftrapv

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