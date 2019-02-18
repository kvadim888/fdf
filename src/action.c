/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 19:45:43 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/12 13:17:39 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_rotate(int key, t_fdf *fdf, t_vect axis)
{
	t_vect	*center;
	double	angle;

	angle = 0.05;
	if (key == NUM_KEY_8)
		axis.x = -1;
	else if (key == NUM_KEY_2)
		axis.x = 1;
	else if (key == NUM_KEY_4)
		axis.y = -1;
	else if (key == NUM_KEY_6)
		axis.y = 1;
	else if (key == NUM_KEY_7 || key == NUM_KEY_3)
		axis.z = -1;
	else if (key == NUM_KEY_9 || key == NUM_KEY_1)
		axis.z = 1;
	else
		return (0);
	center = ft_figcenter(fdf->figure);
	ft_figrotate(fdf->figure, *center, axis, angle);
	ft_memdel((void **)&center);
	return (1);
}

int		ft_move(int key, t_fdf *fdf, t_vect direction)
{
	double	distance;

	distance = 5.0;
	if (key == ARROW_UP)
		direction.y = -distance;
	else if (key == ARROW_DOWN)
		direction.y = distance;
	else if (key == ARROW_LEFT)
		direction.x = -distance;
	else if (key == ARROW_RIGHT)
		direction.x = distance;
	else if (key == HOME_KEY)
		direction.z = 2 * distance;
	else if (key == END_KEY)
		direction.z = -2 * distance;
	else
		return (0);
	ft_figmove(fdf->figure, direction);
	return (1);
}

int		ft_zoom(int key, t_fdf *fdf, t_vect scale)
{
	double		k;

	k = 1.1;
	if (key == NUM_KEY_PLUS)
		ft_vectcoord(&scale, k, k, k);
	else if (key == NUM_KEY_MINUS)
		ft_vectcoord(&scale, 1 / k, 1 / k, 1 / k);
	else
		return (0);
	ft_figscale(fdf->figure, scale);
	return (1);
}

int		ft_latitude(int key, t_fdf *fdf, t_vect vect)
{
	double		k;
	double		mat[3][3];

	k = 1.1;
	if (key == PT_KEY)
		k = 1.1;
	else if (key == CM_KEY)
		k = 0.9;
	else
		return (0);
	ft_vectcoord(&vect, fdf->figure->norm->x,\
						fdf->figure->norm->y, fdf->figure->norm->z);
	mat[0][0] = 1 + (k - 1) * pow(vect.x, 2);
	mat[0][1] = (k - 1) * (vect.x) * (vect.y);
	mat[0][2] = (k - 1) * (vect.x) * (vect.z);
	mat[1][0] = (k - 1) * (vect.x) * (vect.y);
	mat[1][1] = 1 + (k - 1) * pow(vect.y, 2);
	mat[1][2] = (k - 1) * (vect.y) * (vect.z);
	mat[2][0] = (k - 1) * (vect.x) * (vect.z);
	mat[2][1] = (k - 1) * (vect.y) * (vect.z);
	mat[2][2] = 1 + (k - 1) * pow(vect.z, 2);
	ft_figtransfrom(fdf->figure, mat);
	return (1);
}

int		ft_keyfunc(int key, void *param)
{
	int				status;
	t_fdf			*fdf;
	t_vect			vect;

	fdf = (t_fdf*)param;
	status = 0;
	ft_vectcoord(&vect, 0, 0, 0);
	status += ft_zoom(key, fdf, vect);
	status += ft_rotate(key, fdf, vect);
	status += ft_move(key, fdf, vect);
	status += ft_latitude(key, fdf, vect);
	if (status > 0)
		ft_snapshot(fdf, fdf->figure);
	if (key == KEY_ESC)
		ft_exit(key, fdf);
	return (0);
}
