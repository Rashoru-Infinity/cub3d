/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 01:39:17 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/05 06:15:31 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <cub3d.h>
#include <math.h>
#include <float.h>

static void			set_obj_pos(t_point2 start, t_point2 end, t_point2 *pos)
{
	ft_bzero(pos, sizeof(t_point2));
	if (floor(end.x) - floor(start.x) > 0.5)
	{
		pos->x = floor(end.x) + 0.5;
		pos->y = floor(end.y) + 0.5;
	}
	else if (ceil(end.x) - ceil(start.x) < -0.5)
	{
		pos->x = ceil(end.x) - 0.5;
		pos->y = floor(end.y) + 0.5;
	}
	else if (floor(end.y) - floor(start.y) > 0.5)
	{
		pos->x = floor(end.x) + 0.5;
		pos->y = floor(end.y) + 0.5;
	}
	else if (ceil(end.y) - ceil(start.y) < -0.5)
	{
		pos->x = floor(end.x) + 0.5;
		pos->y = ceil(end.y) - 0.5;
	}
}

static double		get_sub_angle(t_point2 vtx1, t_point2 jntvtx, t_point2 vtx2)
{
	double	rad1;
	double	rad2;

	rad1 = atan2(vtx1.y - jntvtx.y, vtx1.x - jntvtx.x);
	rad2 = atan2(vtx2.y - jntvtx.y, vtx2.x - jntvtx.x);
	return (rad1 - rad2);
}

static void			inc_rad(double *curr_rad, double heading, int x)
{
	double	step;
	double	fov;

	fov = (double)66 / (double)180 * M_PI;
	step = sin(fov / 2) * 2 / x;
	*curr_rad = heading +\
	atan2(cos(fov / 2) * tan(*curr_rad - heading) + step, cos(fov / 2));
}

static t_map_obj	check_object(t_point2 start, t_point2 end, t_arg *ag,
					t_ray_obj *hit_inf)
{
	double		euclid_dist;
	double		delta_rad;
	t_sp_inf	*sp;
	double		pl_cnt_dist;

	set_obj_pos(start, end, &hit_inf->pos);
	hit_inf->rad = atan2(end.y - hit_inf->pos.y, end.x - hit_inf->pos.x);
	delta_rad = get_sub_angle(hit_inf->pos, hit_inf->pl_pos, end);
	euclid_dist = get_euclid_dist2(end, hit_inf->pl_pos);
	pl_cnt_dist = get_euclid_dist2(hit_inf->pos, hit_inf->pl_pos);
	if (is_wall(ag->conf, hit_inf->pos.x, hit_inf->pos.y))
	{
		hit_inf->camera_dist =
		get_camera_dist(end, hit_inf->pl_pos, hit_inf->heading_rad);
		return (euclid_dist < DBL_EPSILON ? blank : wall);
	}
	else if (is_sprite(ag->conf, hit_inf->pos.x, hit_inf->pos.y)
	&& fabs(pl_cnt_dist * tan(delta_rad)) <= 0.5)
	{
		if (!(sp = gen_sp_inf(delta_rad, pl_cnt_dist))
		|| array_add(&hit_inf->sp_stk, (void *)sp) == fail)
			cub3d_error(ag, malloc_err);
		return (euclid_dist < DBL_EPSILON ? blank : sprite);
	}
	return (blank);
}

void				raycast(t_arg *ag)
{
	int			sw;
	double		curr_rad;
	t_ray_obj	hit_inf;
	t_point2	ray;
	t_point2	prev_ray;

	sw = 0;
	hit_inf.heading_rad = ag->mlx.player.dir;
	curr_rad = ag->mlx.player.dir - (double)33 / (double)180 * M_PI;
	ft_memcpy(&hit_inf.pl_pos, &ag->mlx.player.pos, sizeof(t_point2));
	while (sw < ag->mlx.win.size.x)
	{
		array_init(&hit_inf.sp_stk, 10);
		ft_memcpy(&prev_ray, &ag->mlx.player.pos, sizeof(t_point2));
		ft_memcpy(&ray, &ag->mlx.player.pos, sizeof(t_point2));
		while (check_object(prev_ray, ray, ag, &hit_inf) != wall)
			extend_ray(curr_rad, &ray, &prev_ray);
		draw_wall(hit_inf, &ag->mlx, sw);
		draw_sprite(&hit_inf, &ag->mlx, sw);
		inc_rad(&curr_rad, ag->mlx.player.dir, ag->mlx.win.size.x);
		++sw;
		array_clear(&hit_inf.sp_stk);
	}
}
