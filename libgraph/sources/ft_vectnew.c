/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 21:53:18 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/07 18:45:28 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_vect	*ft_vectnew(double x, double y, double z)
{
	t_vect *vect;

	if (!(vect = (t_vect*)malloc(sizeof(t_vect))))
		return (NULL);
	vect->x = x;
	vect->y = y;
	vect->z = z;
	vect->color = 0;
	return (vect);
}
