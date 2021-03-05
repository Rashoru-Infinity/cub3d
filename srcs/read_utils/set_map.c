/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:14:14 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/05 11:09:37 by khagiwar         ###   ########.fr       */
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

static void		set_map_end(t_array file_contents, t_config *conf, t_error e)
{
	if (e == no_err)
		return ;
	array_clear(&file_contents);
	cub3d_error2(conf, e);
}

void			set_map(t_array file_contents, t_config *conf)
{
	size_t	line_no;
	char	*line;
	int		eom;
	t_error	e;

	eom = 0;
	e = no_err;
	if (array_init(&(conf->map), 10) == fail)
		e = malloc_err;
	line_no = get_map_offset(file_contents);
	if (e == no_err && !file_contents.contents[line_no])
		e = map_err;
	while (line_no < file_contents.size && e == no_err)
	{
		if (eom && ft_strlen((char *)file_contents.contents[line_no]))
			e = map_err;
		if (e == no_err && !ft_strlen((char *)file_contents.contents[line_no]))
			eom = 1;
		if (e == no_err
		&& (!(line = ft_strdup((char *)(file_contents.contents[line_no])))
		|| array_add(&(conf->map), (void *)line) == fail))
			e = malloc_err;
		++line_no;
	}
	set_map_end(file_contents, conf, e);
}
