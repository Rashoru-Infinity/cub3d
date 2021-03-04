/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_white_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:58:08 by khagiwar          #+#    #+#             */
/*   Updated: 2021/02/23 16:44:30 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*replace_white_space(char *s)
{
	size_t offset;

	offset = 0;
	while (s[offset])
	{
		if (0x09 <= s[offset] && s[offset] <= 0x0d)
			s[offset] = ' ';
		++offset;
	}
	return (s);
}
