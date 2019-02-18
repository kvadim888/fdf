/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_figrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 23:31:29 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/09 14:13:32 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_figrotate(t_figure *fig, t_vect pole, t_vect vect, double angle)
{
	int			i;
	int			j;
	double		rot_mat[3][3];

	ft_rotmatrix(rot_mat, vect, angle);
	ft_ltransform(rot_mat, fig->norm);
	i = -1;
	while (++i < fig->ymax)
	{
		j = -1;
		while (++j < fig->xmax)
		{
			ft_vectsub(fig->vect[i][j], pole);
			ft_ltransform(rot_mat, fig->vect[i][j]);
			ft_vectsum(fig->vect[i][j], pole);
		}
	}
}
