/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 20:38:54 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/05 10:47:37 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>
#include <get_next_line_bonus.h>
#include <libtype.h>
#include <vla.h>
#include <fcntl.h>
#include <unistd.h>

static t_error	set_color(int *color, char *line)
{
	char		**words;
	size_t		word_count;
	t_error		e;
	int			nbr;

	e = no_err;
	while (*line == ' ')
		++line;
	++line;
	if (!(words = ft_split(line, ',')))
		return (malloc_err);
	if (count_delimiter(line, ',') != 2)
		e = file_format;
	word_count = 0;
	while (words[word_count] && e == no_err)
	{
		*color <<= 8;
		if (e == no_err && (atoi_check(words[word_count++], &nbr) == fail))
			e = file_format;
		*color += nbr;
	}
	split_clear(words);
	return (word_count == 3 ? e : file_format);
}

static t_error	set_resolution(char *line, t_point *win_size)
{
	char		**words;
	size_t		wd_cnt;
	t_error		e;
	int			*dst;

	wd_cnt = 0;
	if (win_size->x > 0 || win_size->y > 0)
		return (file_format);
	if (!(words = ft_split(line, ' ')))
		return (malloc_err);
	e = no_err;
	while (words[++wd_cnt] && e == no_err)
	{
		if (wd_cnt >= 3)
			e = file_format;
		else if (wd_cnt == 1)
			dst = &win_size->x;
		else if (wd_cnt == 2)
			dst = &win_size->y;
		if (e == no_err && (wd_cnt == 1 || wd_cnt == 2))
			if (atoi_check2(words[wd_cnt], dst) == fail)
				e = file_format;
	}
	split_clear(words);
	return (wd_cnt == 3 ? e : file_format);
}

static void		set_others(char *line, t_config *conf, t_array cub)
{
	t_error	e;

	e = no_err;
	if (!ft_strncmp("R ", skip_space(line), 2))
		e = !conf->window_size.x || !conf->window_size.y ? file_format :
		set_resolution(line, &(conf->window_size));
	else if (!ft_strncmp("F ", skip_space(line), 2))
		e = conf->textures.floor != 0xFF << 24 ? file_format :
		set_color(&(conf->textures.floor), line);
	else if (!ft_strncmp("C ", skip_space(line), 2))
		e = conf->textures.ceil != 0xFF << 24 ? file_format :
		set_color(&(conf->textures.ceil), line);
	else
		e = file_format;
	if (e != no_err)
	{
		array_clear(&cub);
		cub3d_error2(conf, e);
	}
}

static void		parse_conf(t_array cub, t_config *conf)
{
	size_t		line;

	line = 0;
	while (cub.size > line
	&& !ft_isdigit(*(skip_space((char *)cub.contents[line]))))
	{
		if (!ft_strlen(skip_space(cub.contents[line])))
			++line;
		else if (!ft_strncmp("NO ", skip_space(cub.contents[line]), 3))
			set_texture(cub.contents[line++], &(conf->textures.no), conf, cub);
		else if (!ft_strncmp("SO ", skip_space(cub.contents[line]), 3))
			set_texture(cub.contents[line++], &(conf->textures.so), conf, cub);
		else if (!ft_strncmp("WE ", skip_space(cub.contents[line]), 3))
			set_texture(cub.contents[line++], &(conf->textures.we), conf, cub);
		else if (!ft_strncmp("EA ", skip_space(cub.contents[line]), 3))
			set_texture(cub.contents[line++], &(conf->textures.ea), conf, cub);
		else if (!ft_strncmp("S ", skip_space(cub.contents[line]), 2))
			set_texture(cub.contents[line++], &(conf->textures.sp), conf, cub);
		else
			set_others(cub.contents[line++], conf, cub);
	}
	check_conf(cub, conf);
	set_map(cub, conf);
}

void			read_conf(char *file, t_config *conf)
{
	int			fd;
	char		*line;
	int			gnl_status;
	t_array		file_data;
	t_error		e;

	init_conf(conf);
	e = no_err;
	if ((fd = open(file, O_RDONLY)) < 0)
		cub3d_error2(conf, read_file);
	if (array_init(&file_data, 10) == fail)
		cub3d_error2(conf, malloc_err);
	while ((gnl_status = get_next_line(fd, &line)) >= 0 && e == no_err)
	{
		if (array_add(&file_data, replace_white_space(line)) == fail)
			e = malloc_err;
		if (gnl_status == 0)
			break ;
	}
	if (e == no_err && gnl_status == 0)
		parse_conf(file_data, conf);
	array_clear(&file_data);
	close(fd);
	if (e != no_err || gnl_status < 0)
		cub3d_error2(conf, gnl_status < 0 ? read_file : e);
}
