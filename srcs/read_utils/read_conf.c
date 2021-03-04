/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 20:38:54 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/04 09:23:25 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>
#include <get_next_line_bonus.h>
#include <libtype.h>
#include <vla.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

static void		set_color(t_color *color, char *line)
{
	char		**words;
	size_t		word_count;

	++line;
	while (*line == ' ')
		++line;
	if (!(words = ft_split(line, ',')))
		cub3d_error(malloc_err);
	if (count_delimiter(line, ',') != 2)
		cub3d_error(file_format);
	word_count = 0;
	while (words[word_count])
	{
		if (word_count == 0)
			color->r = ft_atoi(words[word_count]);
		else if (word_count == 1)
			color->g = ft_atoi(words[word_count]);
		else if (word_count == 2)
			color->b = ft_atoi(words[word_count]);
		if (word_count >= 3 || atoi_check(words[word_count]) == fail
		|| ft_atoi(words[word_count]) < 0 || ft_atoi(words[word_count]) > 255)
			cub3d_error(file_format);
		free(words[word_count++]);
	}
	free(words);
}

static void		set_resolution(char *line, t_point *win_size)
{
	char		**words;
	size_t		wd_cnt;

	wd_cnt = 0;
	if (!(words = ft_split(line, ' ')))
		cub3d_error(malloc_err);
	if (win_size->x > 0 || win_size->y > 0)
		cub3d_error(file_format);
	while (words[wd_cnt])
	{
		if (wd_cnt >= 3)
			cub3d_error(file_format);
		else if (wd_cnt == 1)
			win_size->x = ft_atoi(words[wd_cnt]);
		else if (wd_cnt == 2)
			win_size->y = ft_atoi(words[wd_cnt]);
		if (wd_cnt == 1 && atoi_check2(words[wd_cnt], &win_size->x) == fail)
			cub3d_error(file_format);
		if (wd_cnt == 2 && atoi_check2(words[wd_cnt], &win_size->y) == fail)
			cub3d_error(file_format);
		free(words[wd_cnt++]);
	}
	if (win_size->x <= 0 || win_size->y <= 0)
		cub3d_error(file_format);
	free(words);
}

static void		set_others(char *line, t_config *conf)
{
	if (!ft_strncmp("R ", skip_space(line), 2))
	{
		if (!conf->window_size.x || !conf->window_size.y)
			cub3d_error(file_format);
		set_resolution(line, &(conf->window_size));
	}
	else if (!ft_strncmp("F ", skip_space(line), 2))
	{
		if (conf->textures.floor.r >= 0 || conf->textures.floor.g >= 0
		|| conf->textures.floor.b >= 0)
			cub3d_error(file_format);
		set_color(&(conf->textures.floor), line);
	}
	else if (!ft_strncmp("C ", skip_space(line), 2))
	{
		if (conf->textures.ceil.r >= 0 || conf->textures.ceil.g >= 0
		|| conf->textures.ceil.b >= 0)
			cub3d_error(file_format);
		set_color(&(conf->textures.ceil), line);
	}
	else
		cub3d_error(file_format);
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
			set_texture(cub.contents[line++], &(conf->textures.no));
		else if (!ft_strncmp("SO ", skip_space(cub.contents[line]), 3))
			set_texture(cub.contents[line++], &(conf->textures.so));
		else if (!ft_strncmp("WE ", skip_space(cub.contents[line]), 3))
			set_texture(cub.contents[line++], &(conf->textures.we));
		else if (!ft_strncmp("EA ", skip_space(cub.contents[line]), 3))
			set_texture(cub.contents[line++], &(conf->textures.ea));
		else if (!ft_strncmp("S ", skip_space(cub.contents[line]), 2))
			set_texture(cub.contents[line++], &(conf->textures.sp));
		else
			set_others(cub.contents[line++], conf);
	}
}

void			read_conf(char *file, t_config *conf)
{
	int			fd;
	char		*line;
	int			gnl_status;
	t_array		file_data;

	init_conf(conf);
	if ((fd = open(file, O_RDONLY)) < 0)
		cub3d_error(read_file);
	if (array_init(&file_data, 10) == fail)
		cub3d_error(malloc_err);
	while ((gnl_status = get_next_line(fd, &line)) >= 0)
	{
		if (array_add(&file_data, replace_white_space(line)) == fail)
			cub3d_error(malloc_err);
		if (gnl_status == 0)
			break ;
	}
	if (gnl_status == -1)
		cub3d_error(read_file);
	parse_conf(file_data, conf);
	check_conf(conf);
	set_map(file_data, conf);
	array_clear(&file_data);
	close(fd);
}
