/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:28:53 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/06 17:30:58 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t src_size;
	size_t offset;

	if (!dest || !src)
		return (0);
	src_size = 0;
	while ((unsigned char)src[src_size])
		++src_size;
	if (size == 0)
		return (src_size);
	offset = 0;
	while (offset < size - 1)
	{
		if (offset < src_size)
			dest[offset] = src[offset];
		else
			break ;
		++offset;
	}
	dest[offset] = 0;
	return (src_size);
}
