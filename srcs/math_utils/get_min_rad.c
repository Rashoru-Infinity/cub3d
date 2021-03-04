/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_rad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 05:15:13 by khagiwar          #+#    #+#             */
/*   Updated: 2021/02/27 05:46:48 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	get_min_rad(double large_rad)
{
	double min_rad;

	min_rad = fmod(large_rad, M_PI * 2);
	if (min_rad < -M_PI)
		min_rad += 2 * M_PI;
	else if (min_rad > M_PI)
		min_rad -= 2 * M_PI;
	return (min_rad);
}
