/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:46:37 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/05 08:42:46 by khagiwar         ###   ########.fr       */
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

void			check_conf(t_array cub, t_config *conf)
{
	if (has_texture_paths(conf) == fail)
	{
		array_clear(&cub);
		cub3d_error2(conf, file_format);
	}
	if (has_correct_resolution(conf) == fail)
	{
		array_clear(&cub);
		cub3d_error2(conf, file_format);
	}
}
