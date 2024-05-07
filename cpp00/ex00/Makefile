NAME = megaphone

SRC =	./megaphone.cpp

OBJ = $(SRC:.cpp=.o)
DEP_FILES = $(OBJ:.o=.d)

CC = g++

flags = -Wall -Wextra -Werror -std=c++98

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
	echo $(SRC)
	echo $(OBJ)
