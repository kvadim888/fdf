/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 22:51:06 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/12 13:06:35 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_centralize(t_figure *figure)
{
	t_vect	center;
	t_vect	*vect;

	ft_vectcoord(&center, WIDTH / 2, HEIGHT / 2, 0);
	vect = ft_figcenter(figure);
	ft_vectsub(&center, *vect);
	ft_figmove(figure, center);
	ft_memdel((void **)&vect);
}

void		ft_isometric(t_figure *figure)
{
	t_vect	vect;
	t_vect	*center;

	center = ft_figcenter(figure);
	ft_vectcoord(&vect, 1, 0, 0);
	ft_figrotate(figure, *center, vect, -M_PI_2);
	ft_vectcoord(&vect, 0, 1, 0);
	ft_figrotate(figure, *center, vect, M_PI_4);
	ft_vectcoord(&vect, 1, 0, 0);
	ft_figrotate(figure, *center, vect, M_PI / 6.0);
	ft_memdel((void**)&center);
}

void		ft_screenfit(t_figure *figure)
{
	t_vect	*v1;
	t_vect	*v2;
	double	scale;

	v2 = ft_minvect(figure);
	v1 = ft_maxvect(figure);
	if (ft_vectmodule(*v1) == ft_vectmodule(*v2))
	{
		ft_memdel((void **)&v1);
		ft_memdel((void **)&v2);
		return ;
	}
	ft_vectsub(v1, *v2);
	if (HEIGHT > WIDTH)
		scale = HEIGHT / ft_vectmodule(*v1);
	else
		scale = WIDTH / ft_vectmodule(*v1);
	ft_vectcoord(v2, 0.6 * scale, 0.6 * scale, 0.6 * scale);
	ft_figscale(figure, *v2);
	ft_memdel((void **)&v1);
	ft_memdel((void **)&v2);
}

t_fdf		*ft_fdfinit(t_figure *figure)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)malloc(sizeof(t_fdf));
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "FdF");
	ft_colormap(figure, DARK_GREEN, DARK_BROWN);
	ft_centralize(figure);
	ft_isometric(figure);
	ft_screenfit(figure);
	fdf->figure = figure;
	fdf->camera = ft_camnew(fdf);
	ft_menu(fdf);
	ft_snapshot(fdf, fdf->figure);
	return (fdf);
}
