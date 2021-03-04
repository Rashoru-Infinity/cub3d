/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:42:43 by khagiwar          #+#    #+#             */
/*   Updated: 2021/02/28 22:27:25 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libtype.h>
#include <vla.h>
#include <stdlib.h>
#include <cub3d.h>

void	set_texture(char *line, char **path)
{
	char	**words;
	size_t	word_count;

	if (*path)
		cub3d_error(read_file);
	if (!(words = ft_split(line, ' ')))
		cub3d_error(malloc_err);
	word_count = 0;
	while (words[word_count])
	{
		if (word_count >= 2)
			cub3d_error(file_format);
		if (word_count == 1)
			*path = words[word_count];
		++word_count;
	}
	free(words[0]);
	free(words);
	if (word_count == 0)
		cub3d_error(file_format);
}
