/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:15:29 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/05 06:10:25 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <cub3d.h>
#include <libtype.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <unistd.h>

static void		init_player(t_player *p, t_config conf)
{
	char dir;

	p->pos.x = conf.player_location->x + 0.5;
	p->pos.y = conf.player_location->y + 0.5;
	dir = ((char *)conf.map.contents[conf.player_location->y])
	[conf.player_location->x];
	if (dir == 'N')
		p->dir = -0.5 * M_PI;
	else if (dir == 'S')
		p->dir = 0.5 * M_PI;
	else if (dir == 'E')
		p->dir = 0;
	else
		p->dir = M_PI;
}

static char		*skip_dir(char *s)
{
	size_t index;
	size_t last_index;

	index = 0;
	last_index = 0;
	while (s[index])
	{
		if (s[index] == '/' && s[index + 1])
			last_index = index + 1;
		++index;
	}
	return (s + last_index);
}

static void		arg_check(int argc, char **argv, int *save, t_arg *ag)
{
	char	**words;
	size_t	index;

	if (argc == 1 || argc > 3 || *(skip_dir(argv[1])) == '.')
		cub3d_error(ag, arg_err);
	if (!(words = ft_split(skip_dir(argv[1]), '.')))
		cub3d_error(ag, malloc_err);
	index = 0;
	while (words[index])
	{
		if (!words[index + 1] && ft_strncmp("cub", words[index], 4))
			cub3d_error(ag, arg_err);
		free(words[index++]);
	}
	if (index < 2)
		cub3d_error(ag, arg_err);
	free(words);
	if (argc == 3)
	{
		if (ft_strncmp("--save", argv[2], 7))
			cub3d_error(ag, arg_err);
		*save = 1;
	}
}

int				main(int argc, char **argv)
{
	t_arg		ag;

	ft_bzero(&ag, sizeof(t_arg));
	arg_check(argc, argv, &ag.save, &ag);
	read_conf(argv[1], &ag.conf);
	check_map(&ag.conf);
	init_player(&ag.mlx.player, ag.conf);
	if (!(ag.mlx.mlx_ptr = mlx_init()))
		cub3d_error(&ag, mlx_err);
	set_mlx(&ag);
	if (!ag.save)
	{
		mlx_hook(ag.mlx.win_ptr, 2, 1L << 0, key_press_act, &ag);
		mlx_hook(ag.mlx.win_ptr, 3, 1L << 1, key_release_act, &ag);
		mlx_hook(ag.mlx.win_ptr, 33, 1L << 17, cub3d_end, &ag);
		mlx_loop_hook(ag.mlx.mlx_ptr, render, &ag);
		mlx_do_sync(ag.mlx.mlx_ptr);
		mlx_loop(ag.mlx.mlx_ptr);
	}
	else
		render(&ag);
	cub3d_end(&ag);
	free(ag.mlx.mlx_ptr);
}
