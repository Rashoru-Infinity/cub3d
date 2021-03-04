/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 18:34:08 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/09 19:21:58 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*p;
	size_t	offset;

	len = 0;
	while (*(s + len))
		++len;
	if ((p = (char *)malloc(sizeof(char) * (len + 1))))
	{
		offset = 0;
		while (offset < len)
		{
			*(p + offset) = *(char *)(s + offset);
			++offset;
		}
		*(p + offset) = 0;
	}
	return (p);
}
