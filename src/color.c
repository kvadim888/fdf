/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 06:26:45 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/09 13:52:28 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_makecolor(int fst, int snd, double p)
{
	int		red;
	int		green;
	int		blue;

	red = (int)(((fst >> 16) & 0xFF) * (1 - p) + ((snd >> 16) & 0xFF) * p);
	green = (int)(((fst >> 8) & 0xFF) * (1 - p) + ((snd >> 8) & 0xFF) * p);
	blue = (int)((fst & 0xFF) * (1 - p) + (snd & 0xFF) * p);
	return ((int)((red << 16) | (green << 8) | blue));
}

double		ft_linterp(double first, double second, double val)
{
	double	p;

	if ((val == first) || (first == second))
		return (0);
	p = (double)(val - first) / (double)(second - first);
	return (p);
}

void		ft_readcolor(t_vect *vect, char *color)
{
	if (vect == NULL)
		ft_error(0, "vector allocation error");
	if (!color || *color == '\0')
	{
		vect->color = -1;
		return ;
	}
	if (color && (*color != ','))
		ft_error(0, "invalid  map");
	color++;
	if (color && ft_strlen(color) > 0)
		vect->color = ft_atoi16(color);
}

void		ft_colormap(t_figure *fig, int mincolor, int maxcolor)
{
	int		i;
	int		j;
	double	p;

	fig->min->color = mincolor;
	fig->max->color = maxcolor;
	i = -1;
	while (++i < fig->ymax)
	{
		j = -1;
		while (++j < fig->xmax)
		{
			if (fig->vect[i][j]->color == -1)
			{
				p = ft_linterp(fig->min->z,\
						fig->max->z, fig->vect[i][j]->z);
				fig->vect[i][j]->color = ft_makecolor(mincolor, maxcolor, p);
			}
			fig->vect[i][j]->z *= -1;
		}
	}
	ft_memdel((void **)&(fig->min));
	ft_memdel((void **)&(fig->max));
	fig->min = ft_minvect(fig);
	fig->max = ft_maxvect(fig);
}
