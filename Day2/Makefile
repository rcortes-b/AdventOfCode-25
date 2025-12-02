NAME = aocDay2

CC = gcc
FLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

SRCS_COMMON = srcs/utils/split.c srcs/utils/strjoin.c srcs/utils/strlcpy.c srcs/utils/input.c srcs/utils/free_mem.c srcs/utils/ft_strdup.c
HEAD = includes/Solution.h

# Default sources (normal)
SRCS = srcs/Solution.c $(SRCS_COMMON)

# Bonus sources
SRCS_BONUS = srcs/BonusSolution.c $(SRCS_COMMON)

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME)_bonus

%.o: %.c Makefile $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(NAME)_bonus: $(OBJS_BONUS)
	$(CC) $(FLAGS) $(OBJS_BONUS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
