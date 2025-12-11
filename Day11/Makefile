NAME = aoc

CC = g++
FLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

HEAD = inc/main.hpp inc/Solution.hpp inc/FileParsing.hpp

# Default sources (normal)
SRCS = srcs/main.cpp srcs/Solution.cpp srcs/utils/FileParsing.cpp

# Bonus sources

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp Makefile $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
