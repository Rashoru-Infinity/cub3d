/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 01:22:14 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/06 01:54:33 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>

void		set_mlx(t_arg *ag)
{
	t_point	p;

	mlx_get_screen_size(ag->mlx.mlx_ptr, &p.x, &p.y);
	if (ag->conf.window_size.x > p.x && !ag->save)
		ag->mlx.win.size.x = p.x;
	else
		ag->mlx.win.size.x = ag->conf.window_size.x;
	if (ag->conf.window_size.y > p.y && !ag->save)
		ag->mlx.win.size.y = p.y;
	else
		ag->mlx.win.size.y = ag->conf.window_size.y;
	if (load_images(ag->conf, &ag->mlx) == fail)
		cub3d_error(ag, load_img);
	if (!(ag->mlx.win.img =
	mlx_new_image(ag->mlx.mlx_ptr, ag->mlx.win.size.x, ag->mlx.win.size.y)))
		cub3d_error(ag, mlx_err);
	ag->mlx.win.addr = mlx_get_data_addr(ag->mlx.win.img, &ag->mlx.win.bpp,
					&ag->mlx.win.line_len, &ag->mlx.win.endian);
	if (!ag->save && !(ag->mlx.win_ptr = mlx_new_window(ag->mlx.mlx_ptr,
	ag->mlx.win.size.x, ag->mlx.win.size.y, "Unlimited Blade Works")))
		cub3d_error(ag, mlx_err);
}

static		int diag_through(t_arg *ag, t_point2 new_pnt)
{
	t_point	px;
	t_point	py;

	if (!(abs((int)ag->mlx.player.pos.x - (int)new_pnt.x) > 0)
	|| !(abs((int)ag->mlx.player.pos.y - (int)new_pnt.y) > 0))
		return (0);
	px.x = new_pnt.x - ag->mlx.player.pos.x > 0 ? (int)ceil(new_pnt.x) : (int)floor(new_pnt.x);
	px.y = (int)ceil(new_pnt.y);
	py.x = (int)ceil(new_pnt.x);
	py.y = new_pnt.y - ag->mlx.player.pos.y > 0 ? (int)ceil(new_pnt.y) : (int)floor(new_pnt.y);
	printf("px(%d, %d) py(%d, %d) new_pnt(%f, %f)\n", px.x, px.y, py.x, py.y, new_pnt.x, new_pnt.y);
	if (!is_throughable(ag->conf, px.x, px.y) && !is_throughable(ag->conf, py.x, py.y))
		return (1);
	return (0);
}

void		move_player(t_arg *ag)
{
	t_point2 new_pnt;

	ft_memcpy(&new_pnt, &ag->mlx.player.pos, sizeof(t_point2));
	new_pnt.x += ag->mlx.player.heading_v * cos(ag->mlx.player.dir);
	new_pnt.x += ag->mlx.player.side_v * cos(ag->mlx.player.dir + M_PI / 2);
	new_pnt.y += ag->mlx.player.heading_v * sin(ag->mlx.player.dir);
	new_pnt.y += ag->mlx.player.side_v * sin(ag->mlx.player.dir + M_PI / 2);
	ag->mlx.player.dir += ag->mlx.player.ang_v;
	ag->mlx.player.dir = get_min_rad(ag->mlx.player.dir);
	if (new_pnt.x < 0 || new_pnt.y < 0 || diag_through(ag, new_pnt))
		return ;
	if (is_throughable(ag->conf, (int)new_pnt.x, (int)new_pnt.y))
	{
		ag->mlx.player.pos.x = new_pnt.x;
		ag->mlx.player.pos.y = new_pnt.y;
	}
}

int			render(void *arg)
{
	t_arg *ag;

	ag = (t_arg *)arg;
	draw_fc(ag);
	raycast(ag);
	if (!ag->save)
		mlx_put_image_to_window(ag->mlx.mlx_ptr, ag->mlx.win_ptr,
		ag->mlx.win.img, 0, 0);
	move_player(ag);
	if (ag->mlx.mlx_ptr && (ag->mlx.player.end || ag->save))
		mlx_loop_end(ag->mlx.mlx_ptr);
	return (0);
}
