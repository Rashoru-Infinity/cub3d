/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 01:52:24 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/03 05:17:51 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <mlx.h>
#include <math.h>
#include <libft.h>

static int	get_rad_img_trgb(double rad, t_mlx data, int x, int y)
{
	if (-M_PI / 4 <= rad && rad <= M_PI / 4)
		return (get_img_trgb(data.ea_tx, x, y));
	if (M_PI / 4 < rad && rad <= 3 * M_PI / 4)
		return (get_img_trgb(data.so_tx, x, y));
	if (3 * M_PI / 4 < rad || rad < -3 * M_PI / 4)
		return (get_img_trgb(data.we_tx, x, y));
	return (get_img_trgb(data.no_tx, x, y));
}

static int	get_trgb2(t_ray_obj obj_inf,
			t_mlx *data, double location, t_point2 rate)
{
	int color;

	color = get_rad_img_trgb(obj_inf.rad, *data,
			get_safe_index(rate.x, get_tx_width(obj_inf, *data)),
			get_safe_index(location, get_tx_height(obj_inf, *data)));
	return (color);
}

static void	draw_resize(t_ray_obj obj_inf, t_mlx *data, int sw, t_point2 rate)
{
	int		win_offset;
	int		win_y;
	double	img_offset;
	double	img_y;
	int		color;

	win_y = data->win.size.y / 2;
	img_y = get_tx_height(obj_inf, *data) / 2;
	win_offset = 0;
	ft_bzero(&img_offset, sizeof(double));
	while (win_offset < data->win.size.y / (2 * obj_inf.camera_dist))
	{
		color = get_trgb2(obj_inf, data, (img_y - img_offset)
				/ get_tx_height(obj_inf, *data), rate);
		if (win_y - win_offset >= 0)
			set_px_color(&data->win, sw, win_y - win_offset, color);
		color = get_trgb2(obj_inf, data, (img_y + img_offset)
				/ get_tx_height(obj_inf, *data), rate);
		if (win_y + win_offset < data->win.size.y)
			set_px_color(&data->win, sw, win_y + win_offset, color);
		if (win_offset > win_y)
			break ;
		++win_offset;
		img_offset += 1 / rate.y;
	}
}

void		draw_wall(t_ray_obj obj_inf, t_mlx *data, int sw)
{
	t_point2	rate;

	rate.x = rad_to_side_rate(obj_inf.rad);
	rate.y = (double)data->win.size.y / (double)get_tx_height(obj_inf, *data);
	rate.y /= obj_inf.camera_dist;
	draw_resize(obj_inf, data, sw, rate);
}
