/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:03:35 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/07 19:03:37 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t offset;

	if (!n)
		return (0);
	offset = 0;
	while (*(unsigned char *)(s1 + offset) && *(unsigned char *)(s2 + offset))
	{
		if (*(unsigned char *)(s1 + offset) != *(unsigned char *)(s2 + offset))
			break ;
		if (offset + 1 == n)
			return (0);
		++offset;
	}
	if (!*(unsigned char *)(s1 + offset) && !*(unsigned char *)(s2 + offset))
		return (0);
	if (!*(unsigned char *)(s1 + offset))
		return (-*(s2 + offset));
	if (!*(unsigned char *)(s2 + offset))
		return (*(unsigned char *)(s1 + offset));
	return ((int)(*(unsigned char *)(s1 + offset) \
			- *(unsigned char *)(s2 + offset)));
}
