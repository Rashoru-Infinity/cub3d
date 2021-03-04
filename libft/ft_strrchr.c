/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 08:10:02 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/07 08:10:04 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t offset;
	t_bool found;
	size_t last_index;

	offset = 0;
	found = false;
	last_index = 0;
	while (true)
	{
		if (*(char *)(s + offset) == c)
		{
			found = true;
			last_index = offset;
		}
		if (*(char *)(s + offset) == 0)
			break ;
		++offset;
	}
	if (found)
		return ((char *)(s + last_index));
	return (NULL);
}
