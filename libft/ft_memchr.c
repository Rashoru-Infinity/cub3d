/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 12:37:26 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/06 12:37:28 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	size_t	offset;

	offset = 0;
	while (offset < n)
	{
		if (*(unsigned char *)(buf + offset) == (unsigned char)ch)
			return ((void *)buf + offset);
		++offset;
	}
	return (0);
}
