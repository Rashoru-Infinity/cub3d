/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:00:40 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/06 02:05:10 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <mlx.h>

static void	clear_reachable(t_arg *ag)
{
	if (!ag->save && ag->mlx.mlx_ptr && ag->mlx.win_ptr)
		mlx_destroy_window(ag->mlx.mlx_ptr, ag->mlx.win_ptr);
	if (ag->mlx.win.img && ag->mlx.mlx_ptr)
		mlx_destroy_image(ag->mlx.mlx_ptr, ag->mlx.win.img);
	if (ag->mlx.no_tx.img && ag->mlx.mlx_ptr)
		mlx_destroy_image(ag->mlx.mlx_ptr, ag->mlx.no_tx.img);
	if (ag->mlx.so_tx.img && ag->mlx.mlx_ptr)
		mlx_destroy_image(ag->mlx.mlx_ptr, ag->mlx.so_tx.img);
	if (ag->mlx.we_tx.img && ag->mlx.mlx_ptr)
		mlx_destroy_image(ag->mlx.mlx_ptr, ag->mlx.we_tx.img);
	if (ag->mlx.ea_tx.img && ag->mlx.mlx_ptr)
		mlx_destroy_image(ag->mlx.mlx_ptr, ag->mlx.ea_tx.img);
	if (ag->mlx.sp_tx.img && ag->mlx.mlx_ptr)
		mlx_destroy_image(ag->mlx.mlx_ptr, ag->mlx.sp_tx.img);
	if (ag->mlx.mlx_ptr)
		mlx_destroy_display(ag->mlx.mlx_ptr);
	free(ag->mlx.mlx_ptr);
	clear_conf(ag);
}

void		cub3d_error(t_arg *ag, t_error err_code)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	if (err_code == arg_err)
		write(2, "Invalid arguments.\n", ft_strlen("Invalid arguments.^\n"));
	else if (err_code == file_name)
		write(2, "Invalid file name.\n", ft_strlen("Invalid file name.\n"));
	else if (err_code == read_file)
		write(2, "Fail to read file.\n", ft_strlen("Fail to read file.\n"));
	else if (err_code == file_format)
		write(2, "Incorrect cub file.\n", ft_strlen("Incorrect cub file.\n"));
	else if (err_code == map_err)
		write(2, "Incorrect map.\n", ft_strlen("Incorrect map.\n"));
	else if (err_code == malloc_err)
		write(2, "Fail to allocate memory.\n",
		ft_strlen("Fail to allocate memory.\n"));
	else if (err_code == mlx_err)
		write(2, "Minilibx error.\n", ft_strlen("Minilibx error.\n"));
	else if (err_code == img_err)
		write(2, "Invalid image.\n", ft_strlen("Invalid image.\n"));
	else if (err_code == write_file)
		write(2, "Fail to write file.\n", ft_strlen("Fail to write file.\n"));
	else if (err_code == load_img)
		write(2, "Fail to load images.\n", ft_strlen("Fail to load images.\n"));
	clear_reachable(ag);
	exit(1);
}

void		cub3d_error2(t_config *conf, t_error err_code)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	if (err_code == arg_err)
		write(2, "Invalid arguments.\n", ft_strlen("Invalid arguments.^\n"));
	else if (err_code == file_name)
		write(2, "Invalid file name.\n", ft_strlen("Invalid file name.\n"));
	else if (err_code == read_file)
		write(2, "Fail to read file.\n", ft_strlen("Fail to read file.\n"));
	else if (err_code == file_format)
		write(2, "Incorrect cub file.\n", ft_strlen("Incorrect cub file.\n"));
	else if (err_code == map_err)
		write(2, "Incorrect map.\n", ft_strlen("Incorrect map.\n"));
	else if (err_code == malloc_err)
		write(2, "Fail to allocate memory.\n",
		ft_strlen("Fail to allocate memory.\n"));
	else if (err_code == mlx_err)
		write(2, "Minilibx error.\n", ft_strlen("Minilibx error.\n"));
	else if (err_code == img_err)
		write(2, "Invalid image.\n", ft_strlen("Invalid image.\n"));
	else if (err_code == write_file)
		write(2, "Fail to write file.\n", ft_strlen("Fail to write file.\n"));
	else if (err_code == load_img)
		write(2, "Fail to load images.\n", ft_strlen("Fail to load images.\n"));
	clear_conf2(conf);
	exit(1);
}
