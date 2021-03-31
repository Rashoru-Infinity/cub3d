# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 20:13:14 by khagiwar          #+#    #+#              #
#    Updated: 2021/03/02 02:26:25 by khagiwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
AR	= ar -crs
RM	= rm -f
SRCS	= srcs/vla.c
INC	= -Iincludes -I../includes -I../../libft/
LINK	= -L../../libft -lft
OBJS	= $(SRCS:.c=.o)
NAME	= libvla.a

all	:	$(NAME)

.c.o	:
	$(CC) $(CFLAGS) $(INC) $(LINK) -c $< -o $@

$(NAME)	:	$(OBJS)
	$(AR)	$(NAME) $(OBJS)

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM)	$(NAME)

re	:	fclean all

.PHONY	:	clean fclean all re
