/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:24:44 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/04 11:00:41 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <cub3d.h>
#include <libtype.h>
#include <libft.h>

void	draw_fc(t_arg *ag)
{
	t_point	p;

	ft_bzero(&p, sizeof(t_point));
	while (p.y < ag->mlx.win.size.y / 2)
	{
		while (p.x < ag->mlx.win.size.x)
			set_px_color(&ag->mlx.win, p.x++, p.y,
			gen_trgb2(0, ag->conf.textures.ceil));
		p.x = 0;
		++p.y;
	}
	while (p.y < ag->mlx.win.size.y)
	{
		while (p.x < ag->mlx.win.size.x)
			set_px_color(&ag->mlx.win, p.x++, p.y,
			gen_trgb2(0, ag->conf.textures.floor));
		p.x = 0;
		++p.y;
	}
}
