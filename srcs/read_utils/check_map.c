/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 02:36:41 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/03 17:47:13 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vla.h>
#include <cub3d.h>
#include <libtype.h>
#include <stdlib.h>
#include <limits.h>

static t_status	player_check(char *s, t_point **player_location, int x, int y)
{
	if (('0' <= s[x] && s[x] <= '2') || s[x] == ' ')
		return (success);
	if (s[x] != 'N' && s[x] != 'S' && s[x] != 'E' && s[x] != 'W')
		return (fail);
	if (*player_location || !(*player_location = malloc(sizeof(t_point))))
		return (fail);
	(*player_location)->x = x;
	(*player_location)->y = y;
	return (success);
}

static t_status	find_player(t_config *conf)
{
	size_t	x;
	size_t	y;

	conf->player_location = NULL;
	y = 0;
	while (y < conf->map.size)
	{
		x = 0;
		if (ft_strlen((char *)conf->map.contents[y]) > 1000)
			return (fail);
		while (x < ft_strlen((char *)conf->map.contents[y]))
		{
			if (player_check((char *)(conf->map.contents[y]),
			&(conf->player_location), x, y) == fail)
			{
				free(conf->player_location);
				conf->player_location = NULL;
				return (fail);
			}
			++x;
		}
		++y;
	}
	return (conf->player_location ? success : fail);
}

int				is_stk_appendable(t_config conf, int x, int y)
{
	char	*line;

	if (is_throughable(conf, x, y))
		return (1);
	line = conf.map.contents[y];
	if (line[x] == '2')
		return (1);
	return (0);
}

void			check_map(t_config *conf)
{
	if (conf->map.size > 1000 || find_player(conf) == fail)
		cub3d_error(file_format);
	check_surrounded(*conf);
}
