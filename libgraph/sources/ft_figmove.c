/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_figmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 23:29:27 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/09 12:44:47 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_figmove(t_figure *fig, t_vect vect)
{
	int		i;
	int		j;

	i = 0;
	while (i < fig->ymax)
	{
		j = 0;
		while (j < fig->xmax)
		{
			ft_vectsum(fig->vect[i][j], vect);
			j++;
		}
		i++;
	}
	ft_memdel((void **)&(fig->min));
	fig->min = ft_minvect(fig);
	ft_memdel((void **)&(fig->max));
	fig->max = ft_maxvect(fig);
	ft_memdel((void **)&(fig->center));
	fig->center = ft_figcenter(fig);
}
