/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 08:19:10 by scollon           #+#    #+#             */
/*   Updated: 2016/01/12 10:58:48 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render(t_env *env)
{
	t_point	*cur;
	t_point *next;
	t_point	*next_i;

	cur = env->map->next;
	next = cur->next;
	while (cur->next != NULL)
	{
		next_i = find_next_i(next, cur->index);
		if (cur->index < next->index)
			draw_line(*env, *cur, *next);
		if (next_i != NULL)
			draw_line(*env, *cur, *next_i);
		cur = next;
		next = cur->next;
	}
}

t_point	*find_next_i(t_point *start, int i)
{
	t_point	*cur;

	cur = start->next;
	while (cur)
	{
		if (cur->index == i)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

void	redef_map(t_env *env)
{
	t_point	*map;

	map = env->map->next;
	while (map != NULL)
	{
		map->x = (map->x + env->cam.x);
		map->y = (map->y + env->cam.y);
		if (env->cam.zoom != 1)
		{
			map->x += map->abs_x * env->cam.zoom;
			map->y += ((map->abs_y) * env->cam.zoom / env->cam.ratio);
		}
		if (map->h != 0)
			map->y -= map->h * env->h;
		map = map->next;
	}
}
