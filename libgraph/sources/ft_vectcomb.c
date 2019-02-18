/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectcomb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 22:03:54 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/09 12:34:54 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_vect	*ft_vectcomb(double k1, t_vect v1, double k2, t_vect v2)
{
	t_vect *result;

	if ((result = ft_vectnew(v1.x, v1.y, v1.z)) == NULL)
		return (NULL);
	result->x = k1 * v1.x + k2 * v2.x;
	result->y = k1 * v1.y + k2 * v2.y;
	result->z = k1 * v1.z + k2 * v2.z;
	result->color = v1.color;
	return (result);
}
