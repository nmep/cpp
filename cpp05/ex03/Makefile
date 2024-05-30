NAME = At_least_this_beats_coffee-making

SRC =	./AForm.cpp\
		./Bureaucrat.cpp\
		./main.cpp\
		./PresedientialPardonForm.cpp\
		./RobotomyRequestForm.cpp\
		./ShrubberyCreationForm.cpp\
		./Intern.cpp



OBJ = $(SRC:.cpp=.o)
DEP_FILES = $(OBJ:.o=.d)

header = 	./AForm.hpp\
			./Bureaucrat.hpp\
			./PresidentialPardonForm.hpp\
			./RobotomyRequestForm.hpp\
			./ShrubberyCreationForm.hpp\
			./Intern.hpp


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