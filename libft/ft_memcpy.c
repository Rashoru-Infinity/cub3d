/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 08:08:28 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/06 08:08:30 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t offset;

	if (!dest && !src)
		return (NULL);
	offset = 0;
	while (offset < n)
	{
		*(unsigned char *)(dest + offset) = *(unsigned char *)(src + offset);
		++offset;
	}
	return (dest);
}
