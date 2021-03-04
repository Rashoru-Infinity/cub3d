/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera_dist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 04:51:21 by khagiwar          #+#    #+#             */
/*   Updated: 2021/02/27 22:02:20 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <math.h>
#include <float.h>

double	get_camera_dist(t_point2 obj, t_point2 eye, double heading_rad)
{
	double	vector_rad;
	double	euclid_dist;
	double	delta_rad;

	euclid_dist = get_euclid_dist2(obj, eye);
	if (fabs(obj.x - eye.x) < DBL_EPSILON)
		return (euclid_dist);
	vector_rad = atan2(obj.y - eye.y, obj.x - eye.x);
	delta_rad = fabs(get_min_rad(vector_rad - heading_rad));
	return (euclid_dist * cos(delta_rad));
}
