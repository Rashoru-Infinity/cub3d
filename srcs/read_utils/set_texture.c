/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:42:43 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/05 12:00:25 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libtype.h>
#include <vla.h>
#include <stdlib.h>
#include <cub3d.h>

static void	set_tx_end(t_config *conf, t_array cub, t_error e)
{
	if (e == no_err)
		return ;
	array_clear(&cub);
	cub3d_error2(conf, e);
}

void	set_texture(char *line, char **path, t_config *conf, t_array cub)
{
	char	**words;
	size_t	word_count;
	t_error	e;

	e = no_err;
	if (*path)
		cub3d_error2(conf, read_file);
	if (!(words = ft_split(line, ' ')))
		cub3d_error2(conf, malloc_err);
	word_count = 0;
	while (words[word_count])
	{
		if (word_count != 1)
			free(words[word_count]);
		if (word_count >= 2)
			e = file_format;
		if (word_count == 1)
			*path = words[word_count];
		++word_count;
	}
	free(words);
	e = word_count == 0 ? file_format : e;
	set_tx_end(conf, cub, e);
}
