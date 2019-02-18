/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotmatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 22:24:20 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/09 12:08:29 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_rotmatrix(double mat[3][3], t_vect vect, double angle)
{
	double		s;
	double		c;

	s = sin(angle);
	c = cos(angle);
	vect.x /= ft_vectmodule(vect);
	vect.y /= ft_vectmodule(vect);
	vect.z /= ft_vectmodule(vect);
	mat[0][0] = c + (1 - c) * pow(vect.x, 2);
	mat[0][1] = (1 - c) * (vect.x) * (vect.y) - s * (vect.z);
	mat[0][2] = (1 - c) * (vect.x) * (vect.z) + s * (vect.y);
	mat[1][0] = (1 - c) * (vect.x) * (vect.y) + s * (vect.z);
	mat[1][1] = c + (1 - c) * pow(vect.y, 2);
	mat[1][2] = (1 - c) * (vect.y) * (vect.z) - s * (vect.x);
	mat[2][0] = (1 - c) * (vect.x) * (vect.z) - s * (vect.y);
	mat[2][1] = (1 - c) * (vect.y) * (vect.z) + s * (vect.x);
	mat[2][2] = c + (1 - c) * pow(vect.z, 2);
}
