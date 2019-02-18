/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgraph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 21:53:51 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/09 18:09:09 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGRAPH_H
# define LIBGRAPH_H

# define HEIGHT		800
# define WIDTH		1200

# include "libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_vect
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_vect;

typedef struct	s_figure
{
	t_vect		***vect;
	t_vect		*norm;
	int			xmax;
	int			ymax;
	t_vect		*min;
	t_vect		*max;
	t_vect		*center;
}				t_figure;

t_vect			*ft_vectnew(double x, double y, double z);
void			ft_vectcoord(t_vect *vect, double x, double y, double z);
double			ft_vectmodule(t_vect vect);
t_vect			*ft_vectnorm(t_vect *vect, int mode);
t_vect			*ft_vectcomb(double k1, t_vect v1, double k2, t_vect v2);
void			ft_vectsum(t_vect *v1, t_vect v2);
void			ft_vectsub(t_vect *v1, t_vect v2);
void			ft_vectscale(double k, t_vect *vect);
void			ft_ltransform(double mat[3][3], t_vect *vect);
double			ft_scalmult(t_vect v1, t_vect v2);
t_vect			*ft_vectmult(t_vect *v1, t_vect v2, int mode);

void			ft_rotmatrix(double mat[3][3], t_vect vect, double angle);
void			ft_scalematrix(double mat[3][3], t_vect vect);

t_vect			*ft_intersect(t_vect *start, t_vect *vect,\
												t_vect *plane, double offset);

t_figure		*ft_fignew(int xmax, int ymax);
void			ft_figdel(t_figure *figure);
t_vect			*ft_figcenter(t_figure *fig);
t_vect			*ft_maxvect(t_figure *fig);
t_vect			*ft_minvect(t_figure *fig);
void			ft_figscale(t_figure *fig, t_vect vect);
void			ft_figmove(t_figure *fig, t_vect vect);
void			ft_figrotate(t_figure *fig, t_vect pole,\
											t_vect vect, double angle);
void			ft_figtransfrom(t_figure *fig, double mat[3][3]);

#endif
