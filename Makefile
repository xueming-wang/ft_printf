# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 16:50:54 by xuwang            #+#    #+#              #
#    Updated: 2021/07/29 13:32:18 by xuwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror

NAME 	:= libftprintf.a

SRCS	:= 	ft_printf.c \
			srcs/ft_utils.c \
			srcs/ft_printf_c_percent.c \
			srcs/ft_printf_d_i.c \
			srcs/ft_printf_p.c \
			srcs/ft_printf_s.c \
			srcs/ft_printf_u.c \
			srcs/ft_printf_x.c \
			srcs/ft_itoa_p.c \
			srcs/ft_itoa_u.c \
			srcs/ft_itoa_x.c \
			srcs/ft_itoa.c \
			srcs/check_flag_type.c \
			srcs/ft_flags.c

SRCS_O  := 	ft_printf.o \
			ft_utils.o \
			ft_printf_c_percent.o \
			ft_printf_d_i.o \
			ft_printf_p.o \
			ft_printf_s.o \
			ft_printf_u.o \
			ft_printf_x.o \
			ft_itoa_p.o \
			ft_itoa_u.o \
			ft_itoa_x.o \
			ft_itoa.o \
			check_flag_type.o \
			ft_flags.o 

OBJS := $(SRCS:.c=.o)

$(NAME):
	$(CC) $(CFLAGS) -I. -c $(SRCS)
	ar -rcs $(NAME) $(SRCS_O)

all: $(NAME)

clean:	
		rm -rf $(SRCS_O)
	
fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
	
