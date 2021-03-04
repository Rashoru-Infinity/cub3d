/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rad_to_side_rate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 00:36:18 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/01 00:56:31 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <math.h>
#include <stdio.h>

double	rad_to_side_rate(double rad)
{
	rad = get_min_rad(rad);
	if (-M_PI / 4 <= rad && rad <= M_PI / 4)
		return (fabs(rad - M_PI / 4) / (M_PI / 2));
	if (M_PI / 4 < rad && rad < 3 * M_PI / 4)
		return (fabs(rad - 3 * M_PI / 4) / (M_PI / 2));
	if (3 * M_PI / 4 < rad || rad < -3 * M_PI / 4)
		return (1 - get_min_rad(rad - 3 * M_PI / 4) / (M_PI / 2));
	return (1 - (rad + 3 * M_PI / 4) / (M_PI / 2));
}
