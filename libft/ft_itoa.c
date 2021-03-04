/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:35:22 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/13 13:35:25 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	power(int base, int exp)
{
	int i;
	int n;

	i = 0;
	n = 1;
	while (i++ < exp)
		n *= base;
	return (n);
}

static int	count_digit(int n)
{
	int		digit;
	long	l;

	l = n;
	digit = 1;
	if (n < 0)
		l = -l;
	while (l / 10 != 0)
	{
		l /= 10;
		++digit;
	}
	return (digit);
}

static char	*conv(long cpy, int minus, int digit)
{
	char	*str;
	int		offset;
	int		div;

	if ((str = (char *)malloc(sizeof(char) * (digit + minus + 1))))
	{
		offset = 0;
		div = power(10, digit - 1);
		if (minus)
			str[offset++] = '-';
		while (offset < digit + minus)
		{
			str[offset++] = '0' + cpy / div;
			if (cpy / div != 0)
				cpy %= cpy / div * div;
			div /= 10;
		}
		str[offset] = 0;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		digit;
	int		minus;
	char	*str;
	long	cpy;

	digit = count_digit(n);
	minus = 0;
	cpy = n;
	if (n < 0)
	{
		minus = 1;
		cpy = -cpy;
	}
	str = conv(cpy, minus, digit);
	return (str);
}
