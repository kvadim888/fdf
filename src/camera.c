/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 07:53:52 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/07 20:33:07 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_camera	*ft_camnew(t_fdf *fdf)
{
	t_camera *cam;

	if ((cam = (t_camera*)malloc(sizeof(t_camera))) == NULL)
		return (NULL);
	if ((cam->screen = ft_imgnew(fdf->mlx_ptr, WIDTH, HEIGHT - 20)) == NULL)
	{
		ft_memdel((void **)&cam);
		return (NULL);
	}
	return (cam);
}

void		ft_snapshot(t_fdf *fdf, t_figure *fig)
{
	int		i;
	int		j;

	ft_imgclear(fdf->camera->screen);
	i = -1;
	while (++i < fig->ymax)
	{
		j = -1;
		while (++j < fig->xmax)
		{
			if (j < (fig->xmax - 1))
				ft_drawline(fdf->camera->screen, fig->vect[i][j],\
														fig->vect[i][j + 1]);
			if (i < (fig->ymax - 1))
				ft_drawline(fdf->camera->screen, fig->vect[i][j],\
														fig->vect[i + 1][j]);
			if (fig->xmax == 1 && fig->ymax == 1)
				ft_drawline(fdf->camera->screen, fig->vect[0][0],\
														fig->vect[0][0]);
		}
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,\
												fdf->camera->screen->img, 0, 0);
}
