/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 10:05:40 by scollon           #+#    #+#             */
/*   Updated: 2016/05/16 09:21:40 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef struct		s_arg
{
	int				fd;
	int				wd;
	int				hg;
	char			*file;
	char			*pal;
}					t_arg;

typedef struct		s_point
{
	int				abs_x;
	int				abs_y;
	int				x;
	int				y;
	int				index;
	float			h;
	struct s_point	*next;
}					t_point;

typedef	struct		s_key
{
	int				up;
	int				lft;
	int				rgt;
	int				dwn;
	int				hp;
	int				hm;
	int				pp;
	int				pm;
	int				zp;
	int				zm;

}					t_key;

typedef	struct		s_cam
{
	int				x;
	int				y;
	int				speed;
	float			z;
	float			zoom;
	float			ratio;
}					t_cam;

typedef struct		s_img
{
	void			*adr;
	char			*img;
	int				endian;
	int				bpp;
	int				opp;
	int				sl;
}					t_img;

typedef struct		s_pal
{
	int				nb_col;
	int				nb_pal;
	int				**p;

}					t_pal;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_arg			arg;
	t_point			*map;
	t_img			img;
	t_key			keys;
	t_cam			cam;
	t_pal			pal;
	int				pc;
	int				win_x;
	int				win_y;
	int				map_y;
	int				map_x;
	float			max_h;
	float			min_h;
	float			step_h;
	float			h;
}					t_env;

/*
**			Mains functions
*/
void				read_arg(t_env *env, int ac, char **av);
void				display_menu(t_env *env);
void				aff_help(void);

/*
**			Environnement init functions
*/
t_env				*init_env(void);
void				init_img(t_env *env);
void				init_p(t_env *env);

/*
**			Parsing functions
*/
void				parse(t_env *env);
int					line_test(char *line);
t_point				*new_pt(int x, int y, int h);
void				define_map(t_env *env);
void				redef_map(t_env *env);

/*
**			Render functions
*/
void				render(t_env *env);
t_point				*find_next_i(t_point *start, int i);

/*
**			Draw functions
*/
void				draw_line(t_env env, t_point src, t_point dst);
void				img_pixel_put(t_env *env, int x, int y, int *color);
int					*color(t_env *env, int h);

/*
**			Events handle functions
*/
int					expose_hook(t_env *env);
int					key_press(int keycode, t_env *env);
int					key_release(int keycode, t_env *env);
int					move(t_env *env);

/*
**			Errors and quit functions
*/
void				error(t_env *env, int e_type);
void				clean(t_env *env);

#endif
