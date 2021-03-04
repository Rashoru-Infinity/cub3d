/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:23:41 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/08 17:23:42 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	offset;

	if ((p = malloc(nmemb * size)))
	{
		offset = 0;
		while (offset < size * nmemb)
		{
			*(char *)(p + offset) = 0;
			++offset;
		}
	}
	return (p);
}
