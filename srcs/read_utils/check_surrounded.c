/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surrounded.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 14:36:11 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/02 03:15:48 by khagiwar         ###   ########.fr       */
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

static void		add_stack(t_array *stack, int x, int y, int *stat)
{
	t_point *p;

	if (*stat)
		return ;
	if (!(p = malloc(sizeof(t_point))))
		cub3d_error(malloc_err);
	p->x = x;
	p->y = y;
	if (array_add(stack, (void *)p) == fail)
		cub3d_error(malloc_err);
	*stat = 1;
}

static int		*get_vst(t_array *vst_stat, int x, int y)
{
	int *line;

	line = vst_stat->contents[y];
	return (&(line[x]));
}

static void		dfs(t_config conf, t_array *stack, t_array *vst_stat)
{
	t_point		*curr;

	while (stack->size > 0)
	{
		curr = stack->contents[--stack->size];
		stack->contents[stack->size] = NULL;
		if (is_overruning(conf, curr->x, curr->y) == fail)
			cub3d_error(map_err);
		if (is_stk_appendable(conf, curr->x, curr->y - 1))
			add_stack(stack, curr->x, curr->y - 1,
			get_vst(vst_stat, curr->x, curr->y - 1));
		if (is_stk_appendable(conf, curr->x - 1, curr->y))
			add_stack(stack, curr->x - 1, curr->y,
			get_vst(vst_stat, curr->x - 1, curr->y));
		if (is_stk_appendable(conf, curr->x + 1, curr->y))
			add_stack(stack, curr->x + 1, curr->y,
			get_vst(vst_stat, curr->x + 1, curr->y));
		if (is_stk_appendable(conf, curr->x, curr->y + 1))
			add_stack(stack, curr->x, curr->y + 1,
			get_vst(vst_stat, curr->x, curr->y + 1));
		free(curr);
	}
}

void			check_surrounded(t_config conf)
{
	t_array		stack;
	t_array		*vst_stat;
	t_point		*copy;

	copy = NULL;
	if (!(vst_stat = map_zeros_like(conf.map)))
		cub3d_error(malloc_err);
	if (array_init(&stack, 10) == fail)
		cub3d_error(malloc_err);
	if (!(copy = gen_point(conf.player_location->x, conf.player_location->y)))
		cub3d_error(malloc_err);
	if (array_add(&stack, (void *)copy) == fail)
		cub3d_error(malloc_err);
	dfs(conf, &stack, vst_stat);
	array_clear(&stack);
	array_clear(vst_stat);
	free(vst_stat);
}
