/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:15:49 by khagiwar          #+#    #+#             */
/*   Updated: 2021/02/21 16:16:53 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <stdlib.h>

t_point	*gen_point(int x, int y)
{
	t_point *p;

	if (!(p = malloc(sizeof(t_point))))
		return (NULL);
	p->x = x;
	p->y = y;
	return (p);
}
