/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fignew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 23:22:24 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/06 15:46:15 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_figure	*ft_fignew(int xmax, int ymax)
{
	t_figure	*fig;
	int			i;
	int			j;

	if ((fig = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (NULL);
	fig->min = NULL;
	fig->max = NULL;
	fig->center = NULL;
	fig->xmax = xmax;
	fig->ymax = ymax;
	fig->norm = ft_vectnew(0, 0, 1);
	if ((fig->vect = (t_vect***)malloc(fig->ymax * sizeof(t_vect**))) == NULL)
		return (NULL);
	i = -1;
	while (++i < fig->ymax)
	{
		fig->vect[i] = (t_vect**)malloc(fig->xmax * sizeof(t_vect*));
		if (fig->vect[i] == NULL)
			return (NULL);
		j = -1;
		while (++j < fig->xmax)
			fig->vect[i][j] = NULL;
	}
	return (fig);
}
