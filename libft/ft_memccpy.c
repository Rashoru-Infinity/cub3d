/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 10:13:01 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/06 10:13:05 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;
	size_t offset;
	t_bool found;

	i = 0;
	offset = 0;
	found = false;
	while (i < n)
	{
		if (!found)
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		if (*(unsigned char *)(dest + i) == (unsigned char)c && !found)
		{
			offset = ++i;
			found = true;
			break ;
		}
		++i;
	}
	if (found)
		return (dest + offset);
	return (NULL);
}
