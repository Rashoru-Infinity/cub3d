/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 03:33:00 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/06 03:33:09 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <mlx_int.h>
#include <cub3d.h>
#include <math.h>
#include <libft.h>
#include <stdlib.h>

int			cub3d_end(t_arg *ag)
{
	if (ag->save && write_bmp(ag) == fail)
		cub3d_error(ag, write_file);
	if (!ag->save)
		mlx_destroy_window(ag->mlx.mlx_ptr, ag->mlx.win_ptr);
	mlx_destroy_image(ag->mlx.mlx_ptr, ag->mlx.win.img);
	mlx_destroy_image(ag->mlx.mlx_ptr, ag->mlx.no_tx.img);
	mlx_destroy_image(ag->mlx.mlx_ptr, ag->mlx.so_tx.img);
	mlx_destroy_image(ag->mlx.mlx_ptr, ag->mlx.we_tx.img);
	mlx_destroy_image(ag->mlx.mlx_ptr, ag->mlx.ea_tx.img);
	mlx_destroy_image(ag->mlx.mlx_ptr, ag->mlx.sp_tx.img);
	mlx_destroy_display(ag->mlx.mlx_ptr);
	clear_conf(ag);
	return (0);
}

int			end_button_act(t_arg *ag)
{
	ag->player.end = 1:
	return (0);
}

int			key_press_act(int key, t_arg *ag)
{
	if (key == KEY_A)
		ag->mlx.player.side_v += -0.1;
	else if (key == KEY_D)
		ag->mlx.player.side_v += 0.1;
	else if (key == KEY_S)
		ag->mlx.player.heading_v += -0.1;
	else if (key == KEY_W)
		ag->mlx.player.heading_v += 0.1;
	else if (key == KEY_ESC)
		ag->mlx.player.end = 1;
	else if (key == KEY_LEFT)
		ag->mlx.player.ang_v += M_PI / 100;
	else if (key == KEY_RIGHT)
		ag->mlx.player.ang_v += -M_PI / 100;
	return (0);
}

int			key_release_act(int key, t_arg *ag)
{
	if (key == KEY_A)
		ag->mlx.player.side_v += 0.1;
	else if (key == KEY_D)
		ag->mlx.player.side_v += -0.1;
	else if (key == KEY_S)
		ag->mlx.player.heading_v += 0.1;
	else if (key == KEY_W)
		ag->mlx.player.heading_v += -0.1;
	else if (key == KEY_LEFT)
		ag->mlx.player.ang_v += -M_PI / 100;
	else if (key == KEY_RIGHT)
		ag->mlx.player.ang_v += M_PI / 100;
	return (0);
}
