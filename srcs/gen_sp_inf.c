/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_sp_inf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 00:58:38 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/01 23:09:48 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <stdlib.h>
#include <math.h>

t_sp_inf	*gen_sp_inf(double delta_rad, double euclid_dist)
{
	t_sp_inf	*sp;

	delta_rad = get_min_rad(delta_rad);
	if (!(sp = malloc(sizeof(t_sp_inf))))
		return (NULL);
	sp->side_rate = 0.5 - euclid_dist * tan(delta_rad);
	sp->dist = euclid_dist;
	return (sp);
}
