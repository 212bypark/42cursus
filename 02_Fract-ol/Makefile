NAME = fractol

CC = gcc

HEAD = -I include -I miniliblx

MLX = ./miniliblx

FLAG = -Wall -Wextra -Werror $(HEAD)

RM = rm -rf

SRCS = srcs/main.c \
	srcs/error.c \
	srcs/ft_strcmp.c \
	srcs/hooking.c \
	srcs/init.c \
	srcs/draw.c \
	srcs/fractol.c

OBJS = $(addprefix objs/, $(subst srcs/, , $(SRCS:.c=.o)))

all : $(NAME)

bonus : all

$(NAME) : $(OBJS)
	make -C $(MLX)
	cp $(MLX)/libmlx.dylib libmlx.dylib
	$(CC) $(FLAG) libmlx.dylib $(OBJS) -o $(NAME)

$(OBJS) : $(SRCS)
	$(CC) $(FLAG) -c $(SRCS)
	mkdir -p objs
	mv -f *.o objs

clean :
	make clean -C $(MLX)
	$(RM) objs

fclean : clean
	$(RM) $(NAME) libmlx.dylib

re : fclean all

.PHONY : all bonus clean fclean re
