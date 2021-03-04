/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:22:43 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/09 12:21:55 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t offset;
	size_t dest_size;
	size_t src_size;

	offset = 0;
	dest_size = 0;
	src_size = 0;
	while (dest[dest_size])
		++dest_size;
	while (src[src_size])
		++src_size;
	while (offset + dest_size + 1 < size && src[offset])
	{
		*(dest + dest_size + offset) = src[offset];
		++offset;
	}
	dest[offset + dest_size] = 0;
	if (size < dest_size)
		return (src_size + size);
	return (src_size + dest_size);
}
