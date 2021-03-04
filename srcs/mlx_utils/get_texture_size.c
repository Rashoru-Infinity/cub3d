/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 03:54:18 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/01 18:28:31 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <mlx.h>
#include <math.h>

int	get_tx_height(t_ray_obj obj_inf, t_mlx data)
{
	if (-M_PI / 4 <= obj_inf.rad && obj_inf.rad <= M_PI / 4)
		return (data.ea_tx.size.y);
	if (M_PI / 4 < obj_inf.rad && obj_inf.rad <= 3 * M_PI / 4)
		return (data.so_tx.size.y);
	if (3 * M_PI / 4 < obj_inf.rad || obj_inf.rad < -3 * M_PI / 4)
		return (data.we_tx.size.y);
	return (data.no_tx.size.y);
}

int	get_tx_width(t_ray_obj obj_inf, t_mlx data)
{
	if (-M_PI / 4 <= obj_inf.rad && obj_inf.rad <= M_PI / 4)
		return (data.ea_tx.size.x);
	if (M_PI / 4 < obj_inf.rad && obj_inf.rad <= 3 * M_PI / 4)
		return (data.so_tx.size.x);
	if (3 * M_PI / 4 < obj_inf.rad || obj_inf.rad < -3 * M_PI / 4)
		return (data.we_tx.size.x);
	return (data.no_tx.size.x);
}
