/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxvect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 03:34:56 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/05 05:16:31 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_vect	*ft_maxvect(t_figure *fig)
{
	t_vect		*v;
	int			i;
	int			j;

	if (fig == NULL)
		return (NULL);
	v = ft_vectnew(fig->vect[0][0]->x, fig->vect[0][0]->y, fig->vect[0][0]->z);
	if (v == NULL)
		return (NULL);
	i = 0;
	while (++i < fig->ymax)
	{
		j = 0;
		while (++j < fig->xmax)
		{
			if (fig->vect[i][j]->x > v->x)
				v->x = fig->vect[i][j]->x;
			if (fig->vect[i][j]->y > v->y)
				v->y = fig->vect[i][j]->y;
			if (fig->vect[i][j]->z > v->z)
				v->z = fig->vect[i][j]->z;
		}
	}
	return (v);
}
