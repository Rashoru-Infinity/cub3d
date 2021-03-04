/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:00:40 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/03 19:33:18 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>

void	cub3d_error(t_error err_code)
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
	exit(1);
}
