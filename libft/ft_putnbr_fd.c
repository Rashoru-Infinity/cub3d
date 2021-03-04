/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:51:07 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/13 22:51:08 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	power(int base, int exp)
{
	int n;
	int val;

	val = 1;
	n = 0;
	while (n++ < exp)
		val *= base;
	return (val);
}

static int	count_digit(long n)
{
	int digit;

	digit = 1;
	while (n >= 10)
	{
		++digit;
		n /= 10;
	}
	return (digit);
}

void		ft_putnbr_fd(int n, int fd)
{
	long	x;
	int		digit;
	char	c;
	int		div;

	x = n;
	if (x < 0)
	{
		x = -x;
		write(fd, "-", 1);
	}
	digit = count_digit(x);
	div = power(10, digit - 1);
	while (div != 0)
	{
		--digit;
		c = x / div + '0';
		write(fd, &c, 1);
		if (c - '0' != 0)
			x %= (c - '0') * div;
		div /= 10;
	}
}
