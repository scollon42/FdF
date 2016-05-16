/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 09:07:55 by scollon           #+#    #+#             */
/*   Updated: 2016/05/16 09:22:14 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pixel_put(t_env *env, int x, int y, int *color)
{
	int		pos;

	if (x >= 0 && x < env->win_x && y >= 0 && y < env->win_y)
	{
		pos = (x * env->img.opp) + (y * env->img.sl);
		env->img.img[pos] = color[0];
		env->img.img[pos + 1] = color[1];
		env->img.img[pos + 2] = color[2];
	}
	ft_memdel((void**)&color);
}

void	draw_line(t_env env, t_point src, t_point dst)
{
	int		h;
	int		err;
	int		e2;
	t_point	d;
	t_point	s;

	h = (src.h > dst.h ? src.h : dst.h);
	d.x = abs((dst.x - src.x));
	d.y = -abs((dst.y - src.y));
	s.x = (src.x < dst.x ? 1 : -1);
	s.y = (src.y < dst.y ? 1 : -1);
	err = d.x + d.y;
	while (src.x != dst.x || src.y != dst.y)
	{
		img_pixel_put(&env, src.x, src.y, color(&env, h));
		e2 = 2 * err;
		err = (e2 >= d.y ? err + d.y : err);
		src.x = (e2 >= d.y ? src.x + s.x : src.x);
		err = (e2 <= d.x ? err + d.x : err);
		src.y = (e2 <= d.x ? src.y + s.y : src.y);
	}
}
