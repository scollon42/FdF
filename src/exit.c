/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 10:22:29 by scollon           #+#    #+#             */
/*   Updated: 2016/01/08 17:07:58 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		destroy_map(t_point *map)
{
	t_point *cur;
	t_point *next;

	cur = map;
	next = cur->next;
	while (next != NULL)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
}

static void		destroy_pal(t_pal pal)
{
	int	i;

	i = 0;
	if (pal.p != NULL)
	{
		while (i < pal.nb_pal)
		{
			free(pal.p[i]);
			i++;
		}
		free(pal.p);
	}
}

void			clean(t_env *env)
{
	env->img.adr != NULL ? mlx_destroy_image(env->mlx, env->img.adr) : 0;
	env->win != NULL ? mlx_destroy_window(env->mlx, env->win) : 0;
	free(env->mlx);
	ft_strdel(&env->arg.file);
	ft_strdel(&env->arg.pal);
	destroy_pal(env->pal);
	destroy_map(env->map);
	free(env);
	exit(0);
}

void			error(t_env *env, int e_type)
{
	if (e_type == 1)
		ft_putstr_fd("Error : fdf file invalid\n", 2);
	else if (e_type == 2)
		ft_putstr_fd("Error : color file invalid\n", 2);
	else if (e_type == 3)
		ft_putstr_fd("Error : failed to load color file\n", 2);
	else if (e_type == 4)
		ft_putstr_fd("Error : close() failed\n", 2);
	else if (e_type == 5)
		ft_putstr_fd("Error : init_img() failed\n", 2);
	else if (e_type == 6)
		ft_putstr_fd("Error : fail to create environnement\n", 2);
	else if (e_type == 7)
		ft_putstr_fd("Error : mlx_init() failed\n", 2);
	else if (e_type == 8)
		ft_putstr_fd("Error : color init failed\n", 2);
	else
		ft_putstr("Error\n");
	clean(env);
}
