/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 22:59:12 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/09 12:06:23 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

/*
** start - the ray start point
** vect - the point which lays on the ray
** plane(A,B,C) - the normal vector of the plane Ax+By+Cz+D=0
** offset(D) - the plane offset D: Ax+By+Cz+D=0
*/

t_vect		*ft_intersect(t_vect *start, t_vect *vect,\
											t_vect *plane, double offset)
{
	t_vect	*intersect;
	t_vect	*norm;
	double	t;
	double	den;

	norm = ft_vectnorm(plane, 0);
	den = ft_scalmult(*vect, *norm);
	if (den == 0)
	{
		free(norm);
		return (NULL);
	}
	t = -(ft_scalmult(*start, *norm) + offset) / den;
	intersect = ft_vectnew(vect->x, vect->y, vect->z);
	intersect->color = vect->color;
	intersect->x *= t;
	intersect->y *= t;
	intersect->z *= t;
	ft_memdel((void **)&norm);
	return (intersect);
}
