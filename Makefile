# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 16:50:54 by xuwang            #+#    #+#              #
#    Updated: 2021/04/13 19:11:59 by xuwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror

NAME 	:= libftprintf.a

SRCS	:= 	ft_printf.c \
			src/ft_utils.c \
			src/ft_printf_c_percent.c \
			src/ft_printf_d_i.c \
			src/ft_printf_p.c \
			src/ft_printf_s.c \
			src/ft_printf_u.c \
			src/ft_printf_x_upp.c \
			src/ft_printf_x.c \
			src/ft_width.c
			


OBJS = $(SRCS:.c=.o)

$(NAME):
	$(CC) -c $(FLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS)


all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re