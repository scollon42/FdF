/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 10:35:01 by scollon           #+#    #+#             */
/*   Updated: 2016/01/08 17:06:59 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	test_line(t_env *env, char *line)
{
	int		i;

	i = 0;
	while (line[i] != 0)
	{
		if (ft_isalnum(line[i]) || line[i] == ' ' ||
				line[i] == ',' || line[i] == '-')
			i++;
		else
		{
			ft_strdel(&line);
			error(env, 1);
		}
	}
}

static void	destroy_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void		parse(t_env *env)
{
	char	*line;
	char	**tab;
	t_point *cur;

	cur = env->map;
	while (get_next_line(env->arg.fd, &line) > 0)
	{
		test_line(env, line);
		tab = ft_strsplit(line, ' ');
		ft_strdel(&line);
		env->map_x = 0;
		while (tab[env->map_x] != NULL)
		{
			cur->next = new_pt(env->map_x, env->map_y, atoi(tab[env->map_x]));
			cur = cur->next;
			env->map_x += 1;
		}
		destroy_tab(tab);
		env->map_y += 1;
	}
	ft_strdel(&line);
	(env->map_y == 0 ? error(env, 1) : 0);
	define_map(env);
	(close(env->arg.fd) == -1 ? error(env, 4) : 0);
}

t_point		*new_pt(int x, int y, int h)
{
	t_point *new;

	if ((new = (t_point *)malloc(sizeof(t_point))) == NULL)
		return (NULL);
	new->x = x - y;
	new->abs_x = new->x;
	new->y = y + x;
	new->abs_y = new->y;
	new->h = h;
	new->index = x;
	new->next = NULL;
	return (new);
}

void		define_map(t_env *env)
{
	t_point *map;

	map = env->map->next;
	env->cam.zoom = (env->win_x > env->win_y ? env->win_y : env->win_x)
			/ ((env->map_x * env->cam.ratio
			+ (env->map_y * env->cam.ratio / 2)));
	while (map != NULL)
	{
		map->x *= env->cam.zoom;
		map->y *= env->cam.zoom;
		map->x += (env->win_x - (env->map_x * env->cam.zoom)) / sqrt(2);
		map->y += (env->win_y - (env->map_y * env->cam.zoom)) / 2;
		map->y /= env->cam.ratio;
		map->y -= map->h * env->h;
		env->max_h = (map->h > env->max_h ? map->h : env->max_h);
		env->min_h = (map->h < env->min_h ? map->h : env->min_h);
		map = map->next;
	}
	env->step_h = env->max_h - env->min_h;
}
