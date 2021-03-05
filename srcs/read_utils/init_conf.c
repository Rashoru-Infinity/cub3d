/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 00:59:25 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/05 08:32:34 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>

void	init_conf(t_config *conf)
{
	ft_bzero(conf, sizeof(t_config));
	conf->window_size.x = -1;
	conf->window_size.y = -1;
	conf->textures.floor = 0xFF << 24;
	conf->textures.ceil = 0xFF << 24;
}
