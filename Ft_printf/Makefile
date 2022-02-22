# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 12:10:06 by bypark            #+#    #+#              #
#    Updated: 2021/06/23 12:34:52 by bypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRCS = ft_print_str.c ft_putstr_fd.c ft_strlcpy.c ft_isdigit.c ft_print_type.c ft_strchr.c ft_strlen.c ft_print_char.c ft_printf.c ft_strjoin.c ft_utils.c ft_print_nbr.c ft_putchar_fd.c ft_strlcat.c 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
