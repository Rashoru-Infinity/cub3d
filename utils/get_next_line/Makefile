# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 18:30:10 by khagiwar          #+#    #+#              #
#    Updated: 2021/02/14 18:37:22 by khagiwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
AR	= ar -crs
RM	= rm -f
SRCS	= srcs/get_next_line_bonus.c srcs/get_next_line_utils_bonus.c
INC	= -Iincludes
OBJS	= $(SRCS:.c=.o)
NAME	= libgnl.a
BUF_SIZE	= -D BUFFER_SIZE=1024

all	:	$(NAME)

.c.o	:
	$(CC) $(CFLAGS) $(INC) $(BUF_SIZE) -c $< -o $@

$(NAME)	:	$(OBJS)
	$(AR)	$(NAME) $(OBJS)

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM)	$(NAME)

re	:	fclean all

.PHONY	:	clean fclean all re
