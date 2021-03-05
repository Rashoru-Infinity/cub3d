/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 07:38:09 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/05 07:41:20 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	split_clear(char **strs)
{
	size_t wd_cnt;

	wd_cnt = 0;
	if (!strs)
		return ;
	while (strs[wd_cnt])
	{
		free(strs[wd_cnt]);
		strs[wd_cnt++] = NULL;
	}
	free(strs);
}
