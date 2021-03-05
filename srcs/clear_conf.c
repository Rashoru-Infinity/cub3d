/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_conf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 06:22:39 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/05 05:45:46 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	clear_conf(t_arg *ag)
{
	free(ag->conf.textures.no);
	free(ag->conf.textures.so);
	free(ag->conf.textures.we);
	free(ag->conf.textures.ea);
	free(ag->conf.textures.sp);
	free(ag->conf.player_location);
	array_clear(&ag->conf.map);
}

void	clear_conf2(t_config *conf)
{
	free(conf->textures.no);
	free(conf->textures.so);
	free(conf->textures.we);
	free(conf->textures.ea);
	free(conf->textures.sp);
	free(conf->player_location);
	array_clear(&conf->map);
}
