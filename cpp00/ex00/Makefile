NAME = megaphone

C = g++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

.c.o:
	$(C) $(FLAGS) -c $(obj)

all: $(NAME)

$(NAME): $(OBJ)
	$(C) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)

# test: 
# 	echo $(SRC)

.PHONY: all clean fclean
