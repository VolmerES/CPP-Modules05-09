SRC = src/main.cpp
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(notdir $(SRC:.cpp=.o)))
NAME = iter
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
RM = rm -f

all: $(OBJDIR) $(NAME) .gitignore

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	c++ $(CXXFLAGS) $(OBJ) -o $(NAME)

.gitignore:
	echo "$(OBJDIR)/*.o" > .gitignore; \
	echo "$(NAME)" >> .gitignore

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) .gitignore
	rm -rf $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re