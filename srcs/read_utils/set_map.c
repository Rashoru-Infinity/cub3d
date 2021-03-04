/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:14:14 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/04 11:02:20 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libtype.h>
#include <vla.h>
#include <cub3d.h>

static size_t	get_map_offset(t_array file_contents)
{
	size_t	line;

	line = 0;
	while (line < file_contents.size &&
	!ft_isdigit(*skip_space((char *)file_contents.contents[line])))
		++line;
	return (line);
}

void			set_map(t_array file_contents, t_config *conf)
{
	size_t	line_no;
	char	*line;
	int		eom;

	eom = 0;
	if (array_init(&(conf->map), 10) == fail)
		cub3d_error(malloc_err);
	line_no = get_map_offset(file_contents);
	if (!file_contents.contents[line_no])
		cub3d_error(map_err);
	while (line_no < file_contents.size)
	{
		if (eom && ft_strlen((char *)file_contents.contents[line_no]))
			cub3d_error(file_format);
		if (!ft_strlen((char *)file_contents.contents[line_no]))
			eom = 1;
		if (!(line = ft_strdup((char *)(file_contents.contents[line_no])))
		|| array_add(&(conf->map), (void *)line) == fail)
			cub3d_error(malloc_err);
		++line_no;
	}
}
