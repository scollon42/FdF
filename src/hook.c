/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 12:19:12 by scollon           #+#    #+#             */
/*   Updated: 2016/05/16 09:32:41 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img.adr);
	init_img(env);
	render(env);
	mlx_clear_window(env->mlx, env->win);
	mlx_put_image_to_window(env->mlx, env->win, env->img.adr, 0, 0);
	display_menu(env);
	return (1);
}

int		key_press(int kc, t_env *env)
{
	(kc == 53 ? clean(env) : 0);
	env->keys.up = (kc == 126 ? 1 : 0);
	env->keys.dwn = (kc == 125 ? 1 : 0);
	env->keys.rgt = (kc == 124 ? 1 : 0);
	env->keys.lft = (kc == 123 ? 1 : 0);
	env->keys.zp = (kc == 69 ? 2 : 0);
	env->keys.zm = (kc == 78 ? 2 : 0);
	env->keys.hp = (kc == 116 ? 1 : 0);
	env->keys.hm = (kc == 121 ? 1 : 0);
	env->keys.pp = (kc == 47 ? 1 : 0);
	env->keys.pm = (kc == 43 ? 1 : 0);
	move(env);
	return (1);
}

int		key_release(int kc, t_env *env)
{
	env->keys.up = (kc == 126 ? 0 : 0);
	env->keys.dwn = (kc == 125 ? 0 : 0);
	env->keys.rgt = (kc == 124 ? 0 : 0);
	env->keys.lft = (kc == 123 ? 0 : 0);
	env->keys.zp = (kc == 69 ? 0 : 0);
	env->keys.zm = (kc == 78 ? 0 : 0);
	env->keys.hp = (kc == 116 ? 0 : 0);
	env->keys.hm = (kc == 121 ? 0 : 0);
	env->keys.pp = (kc == 47 ? 1 : 0);
	env->keys.pm = (kc == 43 ? 1 : 0);
	return (1);
}

int		move(t_env *env)
{
	env->cam.y = (-env->keys.up + env->keys.dwn) * env->cam.speed;
	env->cam.x = (-env->keys.lft + env->keys.rgt) * env->cam.speed;
	env->cam.zoom = (-env->keys.zm + env->keys.zp);
	env->cam.zoom = (env->cam.zoom == 0 ? 1 : env->cam.zoom);
	env->h = ((-env->keys.hm + env->keys.hp));
	env->pc += (-env->keys.pm + env->keys.pp);
	env->pc = (env->pc < 0 ? 0 : env->pc);
	env->pc = (env->pc > env->pal.nb_pal - 1 ? env->pal.nb_pal - 1 : env->pc);
	redef_map(env);
	expose_hook(env);
	return (1);
}
