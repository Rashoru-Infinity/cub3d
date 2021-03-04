/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vla.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 19:55:45 by khagiwar          #+#    #+#             */
/*   Updated: 2021/02/21 03:33:07 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vla.h>
#include <stdlib.h>
#include <libft.h>

t_status		array_init(t_array *arr, size_t size)
{
	if (!arr || !size)
		return (fail);
	arr->size = 0;
	arr->real_size = 0;
	if (!(arr->contents = malloc(sizeof(void *) * size)))
		return (fail);
	arr->real_size = size;
	return (success);
}

static t_status	array_extend(t_array *org)
{
	void	*new_array;

	if (!(org->real_size))
		return (fail);
	if (!(new_array = malloc(sizeof(void *) * org->real_size * 2)))
		return (fail);
	ft_memcpy(new_array, org->contents, sizeof(void *) * org->real_size);
	free(org->contents);
	org->contents = new_array;
	org->real_size *= 2;
	return (success);
}

t_status		array_add(t_array *arr, void *content)
{
	if (!arr)
		return (fail);
	if (arr->real_size <= arr->size)
	{
		if (array_extend(arr) == fail)
			return (fail);
	}
	(arr->contents)[arr->size++] = content;
	return (success);
}

void			array_clear(t_array *arr)
{
	if (!arr)
		return ;
	while (arr->size > 0)
		free(arr->contents[--arr->size]);
	free(arr->contents);
	arr->contents = NULL;
	arr->real_size = 0;
	arr->size = 0;
}
