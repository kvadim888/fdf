/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_figscale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 23:38:41 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/09 14:14:05 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_figscale(t_figure *fig, t_vect vect)
{
	int			i;
	int			j;
	double		mat[3][3];

	if (fig == NULL)
		return ;
	ft_scalematrix(mat, vect);
	if (fig->center == NULL)
		fig->center = ft_figcenter(fig);
	i = -1;
	while (++i < fig->ymax)
	{
		j = -1;
		while (++j < fig->xmax)
		{
			ft_vectsub(fig->vect[i][j], *(fig->center));
			ft_ltransform(mat, fig->vect[i][j]);
			ft_vectsum(fig->vect[i][j], *(fig->center));
		}
	}
}
