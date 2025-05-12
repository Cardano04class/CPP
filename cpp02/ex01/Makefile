NAME = FixedPoint
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++ $(CXFLAGS)
CXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean	
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re