/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 01:52:09 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/12 13:16:57 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT			800
# define WIDTH			1200

# include "mlx.h"
# include "libft.h"
# include "libgraph.h"
# include "keymap.h"
# include "colormap.h"

# include <math.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>

typedef struct	s_img
{
	void		*img;
	char		*ptr;
	int			width;
	int			height;
	int			pixel;
	int			endian;
}				t_img;

typedef struct	s_camera
{
	t_img		*screen;
}				t_camera;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	t_figure	*figure;
	t_camera	*camera;
	t_img		*menu;
}				t_fdf;

/*
** image.c
*/

t_img			*ft_imgnew(void *mlx_ptr, int width, int height);
void			ft_imgdel(void *mlx_ptr, t_img *image);
void			ft_imgclear(t_img *image);

/*
** reader.c
*/

void			ft_error(int fd, char *msg);
t_figure		*ft_readfile(int fd);

/*
** color.c
*/

int				ft_makecolor(int first, int second, double p);
double			ft_linterp(double first, double second, double val);
void			ft_readcolor(t_vect	*vect, char *color);
void			ft_colormap(t_figure *fig, int mincolor, int maxcolor);

/*
** camera.c
*/

t_camera		*ft_camnew(t_fdf *fdf);
void			ft_snapshot(t_fdf *fdf, t_figure *fig);

/*
** drawing.c
*/

void			ft_pixelset(t_img *img, int x, int y, int color);
void			ft_drawline(t_img *img, t_vect *v1, t_vect *v2);

/*
** action.c
*/

int				ft_rotate(int key, t_fdf *fdf, t_vect axis);
int				ft_move(int key, t_fdf *fdf, t_vect direction);
int				ft_zoom(int key, t_fdf *fdf, t_vect scale);
int				ft_latitude(int key, t_fdf *fdf, t_vect scale);
int				ft_keyfunc(int key, void *param);

/*
** state.c
*/

t_fdf			*ft_fdfinit(t_figure *figure);
void			ft_screenfit(t_figure *figure);
void			ft_isometric(t_figure *figure);
void			ft_centralize(t_figure *figure);

/*
** figuration.c
*/

void			ft_menu(t_fdf *fdf);
int				ft_exit(int key, t_fdf *fdf);

#endif
