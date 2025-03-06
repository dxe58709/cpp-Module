# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 14:34:13 by nsakanou          #+#    #+#              #
#    Updated: 2025/02/03 17:22:09 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXXFLAGS += -MMD -MP
RM = rm -rf


SRCS =  main.cpp \
		ScalarConverter.cpp

OBJDIR	= obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
DEPENDS	= $(OBJS:.o=.d)


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@


$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
