NAME = philo

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = action.c \
	atoi.c \
	main.c \
	process.c \
	utils.c \
	time.c

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
