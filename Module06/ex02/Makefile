SRC = src/main.cpp \
	  src/creator.cpp \
	  src/C.cpp \
	  src/B.cpp \
	  src/A.cpp \
	  src/Base.cpp
	  
OBJ = $(SRC:.cpp=.o)
NAME = generate
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re