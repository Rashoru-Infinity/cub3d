/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bmp.c                                              |@@@@@  @@@@@|        */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 05:53:17 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/04 11:25:07 by Rashoru-Infinity             ~@  @~            */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <mlx.h>
#include <cub3d.h>
#include <libtype.h>

static t_status	write_header(int fd, t_arg *ag)
{
	const int	dat_ofs = 58;
	int			file_size;

	file_size = dat_ofs + ag->mlx.win.size.x * ag->mlx.win.size.y * sizeof(int);
	if (write(fd, "BM", 2) < 0)
		return (fail);
	if (write(fd, "\0\0\0\0", sizeof(int)) < 0)
		return (fail);
	if (write(fd, &file_size, sizeof(int)) < 0)
		return (fail);
	if (write(fd, &dat_ofs, sizeof(int)) < 0)
		return (fail);
	return (success);
}

static t_status	write_inf_header(int fd, t_arg *ag)
{
	const int	inf_header_size = 40;
	const int	plane = 1;
	int			null_byte_cnt;

	null_byte_cnt = 28;
	if (write(fd, &inf_header_size, sizeof(int)) < 0)
		return (fail);
	if (write(fd, &ag->mlx.win.size.x, sizeof(int)) < 0)
		return (fail);
	if (write(fd, &ag->mlx.win.size.y, sizeof(int)) < 0)
		return (fail);
	if (write(fd, &plane, 2) < 0)
		return (fail);
	if (write(fd, &ag->mlx.win.bpp, 2) < 0)
		return (fail);
	while (--null_byte_cnt >= 0)
		if (write(fd, "\0", 1) < 0)
			return (fail);
	return (success);
}

static t_status	write_img(int fd, t_arg *ag)
{
	int y;
	int x;
	int	px_color;

	y = ag->mlx.win.size.y;
	while (--y >= 0)
	{
		x = 0;
		while (x < ag->mlx.win.size.x)
		{
			px_color = get_img_trgb(ag->mlx.win, ++x, y);
			if (write(fd, &px_color, sizeof(int)) < 0)
				return (fail);
		}
	}
	return (success);
}

t_status		write_bmp(t_arg *ag)
{
	int			fd;
	t_status	status;

	if ((fd = open("screenshot.bmp", O_CREAT | O_RDWR, S_IRWXU | S_IRGRP
	| S_IXGRP | S_IROTH | S_IXOTH)) < 0)
		return (fail);
	status = write_header(fd, ag);
	if (status == success)
		status = write_inf_header(fd, ag);
	if (status == success)
		status = write_img(fd, ag);
	close(fd);
	return (status);
}
