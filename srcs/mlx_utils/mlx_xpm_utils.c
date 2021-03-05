/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_xpm_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 05:25:45 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/05 05:41:56 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <cub3d.h>
#include <libtype.h>
#include <stdlib.h>
#include <libft.h>

static t_status	file_to_image(char *file_name, t_mlx *data, t_image *dest)
{
	dest->img = mlx_xpm_file_to_image(data->mlx_ptr,
				file_name, &dest->size.x, &dest->size.y);
	if (!dest->img)
		return (fail);
	dest->addr =
	mlx_get_data_addr(dest->img, &dest->bpp, &dest->line_len, &dest->endian);
	return (success);
}

int				get_img_trgb(t_image img, int x, int y)
{
	int	*src;

	src = (int *)(img.addr + y * img.line_len + x * img.bpp / 8);
	return (*src);
}

t_status		load_images(t_config conf, t_mlx *data)
{
	ft_bzero(&data->no_tx, sizeof(t_image));
	ft_bzero(&data->so_tx, sizeof(t_image));
	ft_bzero(&data->we_tx, sizeof(t_image));
	ft_bzero(&data->ea_tx, sizeof(t_image));
	ft_bzero(&data->sp_tx, sizeof(t_image));
	if (file_to_image(conf.textures.no, data, &data->no_tx) == fail)
		return (fail);
	if (file_to_image(conf.textures.so, data, &data->so_tx) == fail)
		return (fail);
	if (file_to_image(conf.textures.we, data, &data->we_tx) == fail)
		return (fail);
	if (file_to_image(conf.textures.ea, data, &data->ea_tx) == fail)
		return (fail);
	if (file_to_image(conf.textures.sp, data, &data->sp_tx) == fail)
		return (fail);
	return (success);
}
