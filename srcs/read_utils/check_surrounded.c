/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surrounded.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 14:36:11 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/06 02:06:51 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <cub3d.h>
#include <vla.h>
#include <libtype.h>

static t_status	is_overruning(t_config conf, int x, int y)
{
	if (x == 0 || x + 1 >= (int)ft_strlen((char *)(conf.map.contents[y])))
		return (fail);
	if (y == 0 || y + 1 >= (int)conf.map.size)
		return (fail);
	if (x >= (int)ft_strlen((char *)(conf.map.contents[y - 1])))
		return (fail);
	if (x >= (int)ft_strlen((char *)(conf.map.contents[y + 1])))
		return (fail);
	return (success);
}

static t_error	add_stack(t_array *stack, int x, int y, int *stat)
{
	t_point *p;

	if (*stat)
		return (no_err);
	if (!(p = malloc(sizeof(t_point))))
		return (malloc_err);
	p->x = x;
	p->y = y;
	if (array_add(stack, (void *)p) == fail)
	{
		free(p);
		return (malloc_err);
	}
	*stat = 1;
	return (no_err);
}

static int		*get_vst(t_array *vst_stat, int x, int y)
{
	int *line;

	line = vst_stat->contents[y];
	return (&(line[x]));
}

static t_error	dfs(t_config *conf, t_array *stack, t_array *vst_stat)
{
	t_point		curr;
	t_error		status;

	status = no_err;
	while (stack->size > 0 && status == no_err)
	{
		ft_memcpy(&curr, stack->contents[--stack->size], sizeof(t_point));
		free(stack->contents[stack->size]);
		stack->contents[stack->size] = NULL;
		if (is_overruning(*conf, curr.x, curr.y) == fail)
			return (map_err);
		if (is_stk_appendable(*conf, curr.x, curr.y - 1))
			status = add_stack(stack, curr.x, curr.y - 1,
			get_vst(vst_stat, curr.x, curr.y - 1));
		if (status == no_err && is_stk_appendable(*conf, curr.x - 1, curr.y))
			status = add_stack(stack, curr.x - 1, curr.y,
			get_vst(vst_stat, curr.x - 1, curr.y));
		if (status == no_err && is_stk_appendable(*conf, curr.x + 1, curr.y))
			status = add_stack(stack, curr.x + 1, curr.y,
			get_vst(vst_stat, curr.x + 1, curr.y));
		if (status == no_err && is_stk_appendable(*conf, curr.x, curr.y + 1))
			status = add_stack(stack, curr.x, curr.y + 1,
			get_vst(vst_stat, curr.x, curr.y + 1));
	}
	return (status);
}

void			check_surrounded(t_config *conf)
{
	t_array		stack;
	t_array		*vst_stat;
	t_point		*copy;
	t_error		err;

	copy = NULL;
	err = no_err;
	if (!(vst_stat = map_zeros_like(conf->map)))
		err = malloc_err;
	if (err == no_err && array_init(&stack, 10) == fail)
		err = malloc_err;
	if (err == no_err && !(copy = gen_point(conf->player_location->x,
	conf->player_location->y)))
		err = malloc_err;
	if (err == no_err && array_add(&stack, (void *)copy) == fail)
		err = malloc_err;
	if (err != no_err)
		free(copy);
	if (err == no_err)
		err = dfs(conf, &stack, vst_stat);
	array_clear(&stack);
	array_clear(vst_stat);
	free(vst_stat);
	if (err != no_err)
		cub3d_error2(conf, err);
}
