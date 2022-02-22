NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = ft_bzero.c ft_split.c  node.c r_function.c ft_calloc.c organize.c s_function.c \
	p_funciton.c stack.c ft_maxmin.c main.c process.c utils.c ft_strlen.c \
	ft_putchar_fd.c ft_putstr_fd.c

SRC_DIR = ./srcs/

SRCS = $(addprefix $(SRC_DIR),$(SRC))

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o	: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
