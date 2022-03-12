# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 10:05:43 by bypark            #+#    #+#              #
#    Updated: 2021/06/26 10:01:10 by bypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME1 = server
NAME2 = client
LIBFT = libft/libft.a

all :
	make -C libft
	$(CC) $(CFLAGS) server.c $(LIBFT) -o $(NAME1)
	$(CC) $(CFLAGS) client.c $(LIBFT) -o $(NAME2)

clean :
	make clean -C libft
	rm -f server.o client.o

fclean : clean
	make fclean -C libft
	rm -f $(NAME1) $(NAME2)

re : fclean all

.PHONY : all clean fclean re
