/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_figtransfrom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 01:38:03 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/09 18:13:48 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_figtransfrom(t_figure *fig, double mat[3][3])
{
	int		i;
	int		j;

	if (fig == NULL)
		return ;
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
