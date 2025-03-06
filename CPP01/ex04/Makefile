# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 01:48:01 by nsakanou          #+#    #+#              #
#    Updated: 2024/11/23 18:51:57 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace

CXX = c++
INCLUDE = -I ./includes
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXXFLAGS += -MMD -MP
RM = rm -rf

SRCDIR = srcs
SRC =   main.cpp \
		Replace.cpp

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