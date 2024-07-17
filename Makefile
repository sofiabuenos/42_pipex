#COLORS
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
MAGENTA	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m


NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -fr

INC =  -I inc
SRCS = main.c
OBJS = $(SRCS:.c=.o)

%o: %c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re