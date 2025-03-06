NAME = a.out

CXX = c++
INCLUDE = -I ./includes
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXXFLAGS += -MMD -MP
RM = rm -rf

SRCDIR = srcs
SRC =   main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJDIR	= obj
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.o)))
DEPENDS	= $(OBJS:.o=.d)


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(OBJS) -o $@


$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@
	
clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re