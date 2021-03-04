/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_zeros_like.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 03:16:14 by khagiwar          #+#    #+#             */
/*   Updated: 2021/02/21 23:04:49 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vla.h>
#include <libft.h>
#include <cub3d.h>
#include <stdlib.h>

static int	*gen_vst_stat_array(char *line)
{
	size_t	x;
	int		*array;

	x = ft_strlen(line);
	if (!(array = ft_calloc(x, sizeof(int))))
		return (NULL);
	return (array);
}

t_array		*map_zeros_like(t_array src)
{
	size_t	i;
	t_array	*dest;
	int		*vst_stat_line;

	i = 0;
	if (!(dest = ft_calloc(1, sizeof(t_array)))
	|| array_init(dest, src.real_size) == fail)
	{
		free(dest);
		return (NULL);
	}
	while (i < src.size)
	{
		if (!(vst_stat_line = gen_vst_stat_array((char *)src.contents[i]))
		|| array_add(dest, vst_stat_line) == fail)
		{
			free(vst_stat_line);
			array_clear(dest);
			free(dest);
			return (NULL);
		}
		++i;
	}
	return (dest);
}
