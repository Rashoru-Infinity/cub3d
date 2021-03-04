/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_euclid_dist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 04:38:47 by khagiwar          #+#    #+#             */
/*   Updated: 2021/02/27 06:35:12 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <cub3d.h>

double	get_euclid_dist(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

double	get_euclid_dist2(t_point2 p1, t_point2 p2)
{
	return (sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)));
}
