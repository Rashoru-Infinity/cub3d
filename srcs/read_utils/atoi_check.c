/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 02:18:36 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/04 07:56:43 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>
#include <limits.h>
#include <libtype.h>

t_status	atoi_check(char *str)
{
	long long	nbr;

	nbr = 0;
	while (*str == ' ')
		++str;
	if (!ft_isdigit(*str))
		return (fail);
	while (ft_isdigit(*str))
	{
		if (nbr == 0 && *str == '0' && ft_isdigit(*(str + 1)))
			return (fail);
		nbr *= 10;
		nbr += *str - '0';
		if (nbr > INT_MAX)
			return (fail);
		++str;
	}
	while (*str == ' ')
		++str;
	if (*str != '\0')
		return (fail);
	return (success);
}

t_status	atoi_check2(char *str, int *n)
{
	long long	nbr;

	nbr = 0;
	while (*str == ' ')
		++str;
	if (!ft_isdigit(*str))
		return (fail);
	while (ft_isdigit(*str))
	{
		if (nbr == 0 && *str == '0' && ft_isdigit(*(str + 1)))
			return (fail);
		nbr *= 10;
		nbr += *str - '0';
		if (nbr > INT_MAX)
			*n = INT_MAX;
		++str;
	}
	while (*str == ' ')
		++str;
	if (*str != '\0')
		return (fail);
	return (success);
}
