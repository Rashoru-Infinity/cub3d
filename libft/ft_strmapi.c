/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:48:19 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/13 20:48:22 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i])
		++i;
	if ((str = (char *)malloc(i + 1)))
	{
		str[i] = 0;
		j = 0;
		while (j < i)
		{
			str[j] = f(j, s[j]);
			++j;
		}
	}
	return (str);
}
