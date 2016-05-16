/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 09:53:52 by scollon           #+#    #+#             */
/*   Updated: 2016/05/16 09:31:51 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	init_p(t_env *env)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	i = 0;
	((fd = open(env->arg.pal, O_RDWR)) == -1) ? error(env, 2) : 0;
	get_next_line(fd, &line);
	((env->pal.nb_pal = ft_atoi(line)) == 0 ? error(env, 2) : 0);
	env->pal.nb_pal = 1;
	ft_strdel(&line);
	get_next_line(fd, &line);
	((env->pal.nb_col = ft_atoi(line)) == 0 ? error(env, 2) : 0);
	env->pal.nb_col = 1;
	ft_strdel(&line);
	if (!(env->pal.p = (int**)malloc(sizeof(int*) * env->pal.nb_pal)))
		error(env, 3);
	while (i < env->pal.nb_pal)
	{
		if (!(env->pal.p[i] = (int*)malloc(sizeof(int) * env->pal.nb_col)))
			error(env, 3);
		j = 0;
		while (get_next_line(fd, &line) > 0 && j < env->pal.nb_col)
			env->pal.p[i][j++] = 0xFFFFFF;
		i++;
	}
	(close(fd) == -1 ? error(env, 4) : ft_strdel(&line));
}

void	init_keys(t_env *env)
{
	env->keys.up = 0;
	env->keys.dwn = 0;
	env->keys.lft = 0;
	env->keys.rgt = 0;
	env->keys.zp = 0;
	env->keys.zm = 0;
	env->keys.hp = 0;
	env->keys.hm = 0;
}

t_cam	init_cam(void)
{
	t_cam cam;

	cam.x = 0;
	cam.y = 0;
	cam.speed = 6;
	cam.z = 1;
	cam.zoom = 0;
	cam.ratio = 2;
	return (cam);
}

void	init_img(t_env *env)
{
	if (!(env->img.adr = mlx_new_image(env->mlx, env->win_x, env->win_y)))
		error(env, 5);
	env->img.img = mlx_get_data_addr(env->img.adr,
			&env->img.bpp, &env->img.sl, &env->img.endian);
	env->img.opp = env->img.bpp / 8;
}

t_env	*init_env(void)
{
	t_env	*env;
	t_key	keys;

	if ((env = (t_env *)malloc(sizeof(t_env))) == NULL)
		error(env, 6);
	if ((env->mlx = mlx_init()) == NULL)
		error(env, 7);
	env->win = NULL;
	env->img.adr = NULL;
	env->win_x = 800;
	env->win_y = 600;
	env->map = new_pt(0, 0, 0);
	env->cam = init_cam();
	env->h = 1;
	env->max_h = 0;
	env->pc = 0;
	env->arg.file = NULL;
	env->arg.pal = NULL;
	env->pal.p = NULL;
	init_keys(env);
	init_img(env);
	return (env);
}
