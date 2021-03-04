/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 10:31:00 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/06 10:31:02 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;
	size_t offset;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (dest > src)
			offset = n - i - 1;
		else
			offset = i;
		*(unsigned char *)(dest + offset) = *(unsigned char *)(src + offset);
		++i;
	}
	return (dest);
}
