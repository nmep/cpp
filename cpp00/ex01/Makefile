NAME = My_Phone_Book

SRC =	./Contact.class.cpp \
		./My_PhoneBook.cpp \
		./PhoneBook.class.cpp

OBJ = $(SRC:.cpp=.o)
DEP_FILES = $(OBJ:.o=.d)

header =	./Contact.class.hpp \
			./PhoneBook.class.hpp

CC = g++

flags = -Wall -Wextra -Werror -std=c++98 -MMD -MP -g3

all: $(NAME)

%.o: %.cpp
	$(CC) $(flags) -c $< -o $(<:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(flags) $(OBJ) -o $@

clean:
	rm -v $(OBJ) $(DEP_FILES)

fclean: clean
	rm -v $(NAME)

re: fclean all

test: 
	echo $(SRC)
	echo $(OBJ)

-include $(DEP_FILES)
