/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:46:37 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/02 01:06:04 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>
#include <libtype.h>
#include <vla.h>
#include <unistd.h>

static t_status	has_texture_paths(t_config *conf)
{
	if (!conf->textures.no)
		return (fail);
	if (!conf->textures.so)
		return (fail);
	if (!conf->textures.we)
		return (fail);
	if (!conf->textures.ea)
		return (fail);
	if (!conf->textures.sp)
		return (fail);
	return (success);
}

static t_status	has_correct_resolution(t_config *conf)
{
	if (conf->window_size.x <= 0 || conf->window_size.y <= 0)
		return (fail);
	return (success);
}

static t_status	has_positive_color(t_color c)
{
	if (c.r < 0 || c.g < 0 || c.b < 0)
		return (fail);
	return (success);
}

void			check_conf(t_config *conf)
{
	if (has_positive_color(conf->textures.floor) == fail)
		cub3d_error(file_format);
	if (has_positive_color(conf->textures.ceil) == fail)
		cub3d_error(file_format);
	if (has_texture_paths(conf) == fail)
		cub3d_error(file_format);
	if (has_correct_resolution(conf) == fail)
		cub3d_error(file_format);
}
