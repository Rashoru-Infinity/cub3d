/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_delimiter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 20:37:03 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/02 20:39:39 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	count_delimiter(char *str, char del)
{
	size_t count;

	count = 0;
	while (*str)
	{
		if (*str == del)
			++count;
		++str;
	}
	return (count);
}
