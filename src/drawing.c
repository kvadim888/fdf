/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 02:48:02 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/07 18:28:29 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_pixelset(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	*(int *)(img->ptr + (x + y * img->width) * img->pixel) = color;
}

static double	ft_perc(t_vect *v1, t_vect *v2, t_vect *tmp)
{
	double	den;
	double	num;

	num = fabs(tmp->x - v1->x) + fabs(tmp->y - v1->y);
	den = fabs(v2->x - v1->x) + fabs(v2->y - v1->y);
	if (den == 0)
		return (1);
	return (num / den);
}

static void		ft_drawlow(t_img *img, t_vect *v1, t_vect *v2, t_vect *tmp)
{
	int		dx;
	int		dy;
	int		d;
	int		i;

	dx = (int)(v2->x - v1->x);
	dy = (int)(v2->y - v1->y);
	i = (dy < 0) ? -1 : 1;
	dy = i * dy;
	d = (dy << 1) - dx;
	tmp->x = v1->x;
	tmp->y = v1->y;
	tmp->z = v1->z;
	while (tmp->x <= v2->x)
	{
		tmp->color = ft_makecolor(v1->color, v2->color, ft_perc(v1, v2, tmp));
		ft_pixelset(img, (int)tmp->x++, (int)tmp->y, tmp->color);
		if (d > 0)
		{
			tmp->y += i;
			d -= dx << 1;
		}
		d += dy << 1;
	}
}

static void		ft_drawhigh(t_img *img, t_vect *v1, t_vect *v2, t_vect *tmp)
{
	int		dx;
	int		dy;
	int		d;
	int		i;

	dx = (int)(v2->x - v1->x);
	dy = (int)(v2->y - v1->y);
	i = (dx < 0) ? -1 : 1;
	dx = i * dx;
	d = (dx << 1) - dy;
	tmp->x = v1->x;
	tmp->y = v1->y;
	tmp->z = v1->z;
	while (tmp->y <= v2->y)
	{
		tmp->color = ft_makecolor(v1->color, v2->color, ft_perc(v1, v2, tmp));
		ft_pixelset(img, (int)tmp->x, (int)tmp->y++, tmp->color);
		if (d > 0)
		{
			tmp->x += i;
			d -= dy << 1;
		}
		d += dx << 1;
	}
}

void			ft_drawline(t_img *img, t_vect *v1, t_vect *v2)
{
	t_vect	*tmp;

	if (!img || !v1)
		return ;
	tmp = ft_vectnew(0, 0, 0);
	if (fabs(v2->y - v1->y) < fabs(v2->x - v1->x))
	{
		if (v2->x > v1->x)
			ft_drawlow(img, v1, v2, tmp);
		else
			ft_drawlow(img, v2, v1, tmp);
	}
	else
	{
		if (v2->y > v1->y)
			ft_drawhigh(img, v1, v2, tmp);
		else
			ft_drawhigh(img, v2, v1, tmp);
	}
	free(tmp);
}
