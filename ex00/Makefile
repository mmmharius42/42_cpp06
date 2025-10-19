NAME = convert
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes
SRCDIR = src
OBJDIR = obj

SRCS = main.cpp ScalarConverter.cpp ScalarConverter.hpp

OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.o)))

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compiled successfully!"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/main.o: main.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "Cleaning executable..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
