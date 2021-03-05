# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                                 |@@@@@  @@@@@|         #
#                                                     +:+ +:+         +:+      #
#    By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 22:57:19 by khagiwar          #+#    #+#              #
#    Updated: 2021/03/05 13:46:29 by Rashoru-Infinity             ~@  @~             #
#                                                                              #
# **************************************************************************** #

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra
#CFLAGS	= -Wall -Werror -Wextra -g
RM	= rm -f
RUTILS	= srcs/read_utils
MLUTILS	= srcs/mlx_utils
MAUTILS	= srcs/math_utils
IMGUTILS	= srcs/image_utils
SRCS	= 	srcs/main.c \
			srcs/error_utils.c \
			srcs/obj_type.c \
			srcs/extend_ray.c \
			srcs/raycast.c \
			srcs/gen_sp_inf.c \
			srcs/render.c \
			srcs/clear_conf.c \
			srcs/split_clear.c \
			$(RUTILS)/set_texture.c \
			$(RUTILS)/read_conf.c \
			$(RUTILS)/atoi_check.c \
			$(RUTILS)/skip_space.c \
			$(RUTILS)/replace_white_space.c \
			$(RUTILS)/check_conf.c \
			$(RUTILS)/init_conf.c \
			$(RUTILS)/set_map.c \
			$(RUTILS)/gen_point.c \
			$(RUTILS)/map_zeros_like.c \
			$(RUTILS)/check_map.c \
			$(RUTILS)/check_surrounded.c \
			$(RUTILS)/count_delimiter.c \
			$(MLUTILS)/put_pixel.c \
			$(MLUTILS)/colorutils.c \
			$(MLUTILS)/colorutils2.c \
			$(MLUTILS)/draw_fc.c \
			$(MLUTILS)/draw_wall.c \
			$(MLUTILS)/draw_sprite.c \
			$(MLUTILS)/set_px_color.c \
			$(MLUTILS)/mlx_xpm_utils.c \
			$(MLUTILS)/get_texture_size.c \
			$(MLUTILS)/get_safe_index.c \
			$(MLUTILS)/key_op.c \
			$(MAUTILS)/get_euclid_dist.c \
			$(MAUTILS)/get_camera_dist.c \
			$(MAUTILS)/get_min_rad.c \
			$(MAUTILS)/rad_to_side_rate.c \
			$(IMGUTILS)/write_bmp.c
INC	= -Iincludes -Iutils/includes -Ilibft -Iutils/get_next_line/includes -Iutils/vla/includes
LINK	= -Lutils/get_next_line -lgnl -Lutils/vla -lvla -Llibft -lft -lmlx_Linux -lXext -lX11 -lm
OBJS	= $(SRCS:.c=.o)
NAME	= cub3D

all	:	$(NAME)

.c.o	:
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME)	:	$(OBJS)
	$(MAKE) -C libft all
	$(MAKE) -C utils/get_next_line all
	$(MAKE) -C utils/vla all
	$(CC) $(CFLAGS) $(OBJS) $(LINK) -o $(NAME) 

clean	:
	$(MAKE) -C libft clean
	$(MAKE) -C utils/get_next_line clean
	$(MAKE) -C utils/vla clean
	$(RM) $(OBJS)

fclean	:	clean
	$(MAKE) -C libft fclean
	$(MAKE) -C utils/get_next_line fclean
	$(MAKE) -C utils/vla fclean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re
