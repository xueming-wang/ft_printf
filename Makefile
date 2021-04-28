# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 16:50:54 by xuwang            #+#    #+#              #
#    Updated: 2021/04/28 17:06:05 by xuwang           ###   ########.fr        #
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
			src/ft_printf_x.c \
			src/ft_itoa_p.c \
			src/ft_itoa_u.c \
			src/ft_itoa_x.c \
			src/ft_itoa.c \
			src/check_flag_type.c \
			src/ft_flags.c
			
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
	# $(CC) $(CFLAGS) -I. -c $(SRCS)
	$(CC) -I. -c $(SRCS)
	ar -rc $(NAME) $(SRCS_O)

all: $(NAME)

clean:	
		rm -rf $(SRCS_O)
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
	