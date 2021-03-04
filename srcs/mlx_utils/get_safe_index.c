/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_safe_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:23:09 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/01 19:31:17 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_safe_index(double rate, int image_max)
{
	if (rate < 0)
		return (0);
	if (rate * image_max > image_max - 1)
		return (image_max - 1);
	return (rate * image_max);
}
