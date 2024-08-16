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

#PROGRAM NAME | COMPILER | FLAGS 
NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr

#PATHS
INC =  -I inc
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a 
SRCD = src/
OBJD = obj/

#FILES
SRCS =	$(SRCD)main.c \
		$(SRCD)handle_errors.c \
		$(SRCD)pipex.c \
		$(SRCD)run_cmd.c \
		$(SRCD)run_cmd_utils.c \
		$(SRCD)redirect_and_wait.c

OBJS = $(patsubst $(SRCD)%.c, $(OBJD)%.o, $(SRCS))
$(OBJD)%.o: $(SRCD)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

#RULES:
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
	echo "$(GREEN)All files compiled!$(RESET)"

$(LIBFT):
	make -s -C libft
	make bonus -s -C libft

$(PRINTF):
	make -s -C ft_printf

clean:
	$(RM) $(OBJS)
	make -s -C libft clean
	make -s -C ft_printf clean
	echo "$(RED)Deleted: $(RESET) $(GREEN) objs $(RESET)"

fclean: clean
	$(RM) $(NAME)
	make -s -C libft fclean
	make -s -C ft_printf fclean
	echo "$(RED)Deleted: $(RESET) $(GREEN)$(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re

.SILENT: