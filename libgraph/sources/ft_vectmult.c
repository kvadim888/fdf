/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectmult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 22:09:09 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/09 12:09:10 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_vect	*ft_vectmult(t_vect *v1, t_vect v2, int mode)
{
	t_vect *result;

	if (v1 == NULL)
		return (NULL);
	if ((result = ft_vectnew(v1->x, v1->y, v1->z)) == NULL)
		return (NULL);
	result->x = v1->y * v2.z - v1->z * v2.y;
	result->y = v1->z * v2.x - v1->x * v2.z;
	result->z = v1->x * v2.y - v1->y * v2.x;
	result->color = v1->color;
	if (mode)
	{
		ft_memdel((void **)&v1);
		v1 = result;
	}
	return (result);
}
