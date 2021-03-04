/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 09:55:04 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/12 09:55:05 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trimcpy(char const *s1, int del[256])
{
	size_t	start;
	size_t	end;
	char	*str;

	start = 0;
	while (s1[start])
	{
		if (!del[(int)((unsigned char)s1[start])])
			break ;
		++start;
	}
	end = ft_strlen(s1) - 1;
	while (end > start)
	{
		if (!del[(int)((unsigned char)s1[end])])
			break ;
		--end;
	}
	if ((str = (char *)malloc(sizeof(char) * (end - start + 2))))
	{
		ft_memcpy(str, &s1[start], end - start + 1);
		str[end - start + 1] = 0;
	}
	return (str);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		del[256];
	size_t	i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	str = NULL;
	if (ft_strlen(s1) == 0)
	{
		if ((str = (char *)malloc(sizeof(char))))
			str[0] = 0;
		return (str);
	}
	i = 0;
	while (i < 256)
		del[i++] = 0;
	i = 0;
	while (set[i])
		del[(int)set[i++]] = 1;
	str = trimcpy(s1, del);
	return (str);
}
