/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:39:13 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/09 19:39:15 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	offset;
	char			*sub;
	unsigned int	src_size;

	if (!s || len == SIZE_MAX)
		return (NULL);
	src_size = 0;
	while (s[src_size])
		++src_size;
	if (src_size < start)
		len = 0;
	if ((sub = (char *)malloc(sizeof(char) * (len + 1))))
	{
		offset = 0;
		while (offset < len)
		{
			if (!s[start + offset])
				break ;
			sub[offset] = s[start + offset];
			++offset;
		}
		sub[offset] = 0;
	}
	return (sub);
}
