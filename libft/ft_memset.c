/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 06:50:00 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/06 06:50:00 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*buf2;

	buf2 = (unsigned char *)buf;
	while (n-- > 0)
		*(buf2++) = (unsigned char)ch;
	return (buf);
}
