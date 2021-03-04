/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:04:11 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/06 13:04:12 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned char	t_uchr;

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	size_t	offset;
	int		delta;

	offset = 0;
	while (offset < n)
	{
		delta = *(t_uchr *)(buf1 + offset) - *(t_uchr *)(buf2 + offset);
		if (delta != 0)
			return (delta);
		++offset;
	}
	return (0);
}
