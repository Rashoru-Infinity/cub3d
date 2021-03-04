/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:29:23 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/07 19:29:25 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

typedef unsigned long	t_ul;

int	ft_atoi(const char *nptr)
{
	size_t			offset;
	int				sign;
	unsigned long	n;

	offset = 0;
	sign = 1;
	n = 0;
	while ((9 <= nptr[offset] && nptr[offset] <= 13) || nptr[offset] == ' ')
		++offset;
	if (nptr[offset] == '-' || nptr[offset] == '+')
	{
		if (nptr[offset] == '-')
			sign = -1;
		++offset;
	}
	while ('0' <= nptr[offset] && nptr[offset] <= '9')
	{
		if (ULONG_MAX / 10 < n || n * 10 > ULONG_MAX - (nptr[offset] - '0'))
			return (sign > 0 ? -1 : 0);
		n *= 10;
		n += nptr[offset++] - '0';
	}
	if ((sign < 0 && n <= (t_ul)LONG_MAX + 1) || (sign > 0 && n <= LONG_MAX))
		return ((int)((long)n * sign));
	return (sign > 0 ? -1 : 0);
}
