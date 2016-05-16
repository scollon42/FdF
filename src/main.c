/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 10:04:41 by scollon           #+#    #+#             */
/*   Updated: 2016/04/29 09:45:24 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac > 1 && ac <= 8)
	{
		if (ft_strcmp(av[1], "--help") == 0)
			aff_help();
		env = init_env();
		read_arg(env, ac, av);
		parse(env);
		mlx_hook(env->win, 2, (1L << 0), key_press, env);
		mlx_hook(env->win, 3, (1L << 1), key_release, env);
		mlx_expose_hook(env->win, expose_hook, env);
		mlx_loop(env->mlx);
		clean(env);
	}
	else
		aff_help();
	return (0);
}

void	read_arg(t_env *env, int ac, char **av)
{
	int	i;

	i = 0;
	env->arg.wd = 0;
	env->arg.hg = 0;
	((env->arg.fd = open(av[1], O_RDWR)) < 1 ? error(env, 1) : 0);
	env->arg.file = ft_strdup(av[1]);
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-p") == 0 && i + 1 < ac)
			env->arg.pal = ft_strdup(av[i + 1]);
		else if (ft_strcmp(av[i], "-w") == 0 && i + 1 < ac)
			env->arg.wd = ft_atoi(av[i + 1]);
		else if (ft_strcmp(av[i], "-h") == 0 && i + 1 < ac)
			env->arg.hg = ft_atoi(av[i + 1]);
		i++;
	}
	env->arg.pal == NULL ? env->arg.pal = ft_strdup("palette/d.color") : 0;
	if (env->arg.wd >= 200 && env->arg.wd <= 2000)
		env->win_x = env->arg.wd;
	if (env->arg.hg >= 200 && env->arg.hg <= 2000)
		env->win_y = env->arg.hg;
	env->win = mlx_new_window(env->mlx, env->win_x, env->win_y, env->arg.file);
	// init_p(env);
}

void	display_menu(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 10, 10, 0xFF0000,
			"- Use arrow to deplace map");
	mlx_string_put(env->mlx, env->win, 10, 30, 0xFF0000,
			"- Use page up/down to change relief");
	mlx_string_put(env->mlx, env->win, 10, 50, 0xFF0000,
			"- Use + / - to zoom");
	mlx_string_put(env->mlx, env->win, 10, 70, 0xFF0000,
			"- Use < - > to change color");
}

void	aff_help(void)
{
	ft_putstr("Usage : ./fdf file.fdf [-p file.color]");
	ft_putendl("[-w window width] [-h window height]");
	ft_putendl("Options :");
	ft_putendl(" 		-p     : set color file location");
	ft_putendl(" 		-w     : set windows width");
	ft_putendl(" 		-h     : set windows height");
	ft_putendl(" 		--help : print help");
	exit(0);
}
