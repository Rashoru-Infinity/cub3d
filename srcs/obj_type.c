/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 04:53:57 by khagiwar          #+#    #+#             */
/*   Updated: 2021/02/28 19:38:05 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vla.h>
#include <cub3d.h>

int	is_throughable(t_config conf, int x, int y)
{
	char *line;

	line = conf.map.contents[y];
	if (line[x] == ' ' || line[x] == '0')
		return (1);
	if (line[x] == 'N' || line[x] == 'S' || line[x] == 'W' || line[x] == 'E')
		return (1);
	return (0);
}

int	is_wall(t_config conf, int x, int y)
{
	char *line;

	line = conf.map.contents[y];
	if (line[x] == '1')
		return (1);
	return (0);
}

int	is_sprite(t_config conf, int x, int y)
{
	char *line;

	line = conf.map.contents[y];
	if (line[x] == '2')
		return (1);
	return (0);
}
