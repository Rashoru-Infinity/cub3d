/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 05:09:30 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/06 23:14:11 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <math.h>
#include <float.h>

static void	move_point(double curr_rad, t_point2 *ray)
{
	t_point2 delta;

	ft_bzero(&delta, sizeof(t_point2));
	if (cos(curr_rad) >= 0)
		delta.x = floor(ray->x + 1) - ray->x;
	else
		delta.x = ceil(ray->x - 1) - ray->x;
	if (sin(curr_rad) >= 0)
		delta.y = floor(ray->y + 1) - ray->y;
	else
		delta.y = ceil(ray->y - 1) - ray->y;
	if (fabs(delta.y / delta.x) < fabs(tan(curr_rad)))
	{
		ray->y += delta.y;
		ray->x += delta.y / tan(curr_rad);
	}
	else
	{
		ray->x += delta.x;
		ray->y += delta.x * tan(curr_rad);
	}
}

void		extend_ray(double curr_rad, t_point2 *ray, t_point2 *prev_ray)
{
	ft_memcpy(prev_ray, ray, sizeof(t_point2));
	if (fabs(get_min_rad(curr_rad)) < DBL_EPSILON)
		ray->x += floor(ray->x) + 1 - ray->x;
	else if (fabs(get_min_rad(curr_rad - M_PI)) < DBL_EPSILON)
		ray->x += floor(ray->x) - 1 - ray->x;
	else if (fabs(get_min_rad(curr_rad - M_PI / 2)) < DBL_EPSILON)
		ray->y += floor(ray->y) + 1 - ray->y;
	else if (fabs(get_min_rad(curr_rad + M_PI / 2)) < DBL_EPSILON)
		ray->y += floor(ray->y) - 1 - ray->y;
	else
		move_point(curr_rad, ray);
}
