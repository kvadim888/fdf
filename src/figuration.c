/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figuration.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 21:02:42 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/12 12:42:58 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_makepanel(t_fdf *fdf)
{
	int		i;
	t_vect	v1;
	t_vect	v2;

	fdf->menu = ft_imgnew(fdf->mlx_ptr, WIDTH, 20);
	ft_vectcoord(&v1, 0, fdf->menu->height, 0);
	ft_vectcoord(&v2, fdf->menu->width, fdf->menu->height, 0);
	v1.color = PANEL;
	v2.color = PANEL;
	i = 0;
	while (i <= fdf->menu->height)
	{
		ft_drawline(fdf->menu, &v1, &v2);
		(v1.y)--;
		(v2.y)--;
		v1.color += 0x040404;
		v2.color += 0x040404;
		i++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,\
								fdf->menu->img, 0, HEIGHT - fdf->menu->height);
}

void		ft_menu(t_fdf *fdf)
{
	if (!fdf)
		return ;
	ft_makepanel(fdf);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 80, HEIGHT - 22,
		TEXT, "Zoom: + -");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 260, HEIGHT - 22,
		TEXT, "Moving: arrows");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 480, HEIGHT - 22,
		TEXT, "Rotation: 2 8 4 6 1/9 3/7");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 815, HEIGHT - 22,
		TEXT, "Height: < >");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1020, HEIGHT - 22,
		TEXT, "Exit: ESC");
}
