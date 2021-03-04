/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:00:47 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/03 17:45:13 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <cub3d.h>
#include <stdlib.h>
#include <libft.h>

static int	get_index_by_rate(double curr_index, int max)
{
	return (get_safe_index(curr_index / max, max));
}

static void	draw_resize(t_sp_inf sp_inf, t_mlx *data, int sw, t_point2 rate)
{
	int		win_ofst;
	int		win_y;
	double	img_ofst;
	double	img_y;
	int		color;

	win_y = data->win.size.y / 2;
	img_y = data->sp_tx.size.y / 2;
	win_ofst = 0;
	ft_bzero(&img_ofst, sizeof(double));
	while (win_ofst < data->win.size.y / (2 * sp_inf.dist) && win_ofst < win_y)
	{
		color = get_img_trgb(data->sp_tx,
		get_safe_index(rate.x, data->sp_tx.size.x),
		get_index_by_rate(img_y - img_ofst, data->sp_tx.size.x));
		if (color & 0x00FFFFFF && win_y - win_ofst >= 0)
			set_px_color(&data->win, sw, win_y - win_ofst, color);
		color = get_img_trgb(data->sp_tx,
		get_safe_index(rate.x, data->sp_tx.size.x),
		get_index_by_rate(img_y + img_ofst, data->sp_tx.size.x));
		if (color & 0x00FFFFFF && win_y + win_ofst < data->win.size.y)
			set_px_color(&data->win, sw, win_y + win_ofst, color);
		++win_ofst;
		img_ofst += 1 / rate.y;
	}
}

void		draw_sprite(t_ray_obj *obj_inf, t_mlx *data, int sw)
{
	t_point2	rate;
	size_t		*index;
	t_sp_inf	*obj_elm;

	index = &obj_inf->sp_stk.size;
	while (*index > 0)
	{
		obj_elm = (t_sp_inf *)(obj_inf->sp_stk.contents[--(*index)]);
		rate.y = (double)data->win.size.y / (double)data->sp_tx.size.y;
		rate.y /= obj_elm->dist;
		rate.x = obj_elm->side_rate;
		draw_resize(*obj_elm, data, sw, rate);
		free(obj_elm);
	}
}
