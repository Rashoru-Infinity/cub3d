/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 09:24:24 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/12 09:24:25 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	offset1;
	size_t	offset2;

	if (!s1 || !s2)
		return (NULL);
	if ((str = (char *)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 1))))
	{
		offset1 = 0;
		while (s1[offset1])
		{
			str[offset1] = s1[offset1];
			++offset1;
		}
		offset2 = 0;
		while (s2[offset2])
		{
			str[offset1 + offset2] = s2[offset2];
			++offset2;
		}
		str[offset1 + offset2] = 0;
	}
	return (str);
}
