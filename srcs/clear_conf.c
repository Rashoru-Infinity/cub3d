/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_conf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 06:22:39 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/04 06:27:26 by khagiwar         ###   ########.fr       */
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
