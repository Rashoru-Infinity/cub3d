/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vla.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 19:51:13 by khagiwar          #+#    #+#             */
/*   Updated: 2021/02/20 21:28:50 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VLA_H
# define VLA_H
# include <libtype.h>
# include <unistd.h>
# include <libft.h>

typedef struct	s_array {
	void		**contents;
	size_t		size;
	size_t		real_size;
}				t_array;

t_status		array_init(t_array *arr, size_t size);
t_status		array_add(t_array *org, void *content);
void			array_clear(t_array *arr);

#endif
