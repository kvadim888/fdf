/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltransform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 22:28:29 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/09 14:15:16 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_ltransform(double mat[3][3], t_vect *vect)
{
	t_vect	new;

	if (vect == NULL)
		return ;
	new.x = vect->x * mat[0][0] + vect->y * mat[0][1] + vect->z * mat[0][2];
	new.y = vect->x * mat[1][0] + vect->y * mat[1][1] + vect->z * mat[1][2];
	new.z = vect->x * mat[2][0] + vect->y * mat[2][1] + vect->z * mat[2][2];
	ft_vectcoord(vect, new.x, new.y, new.z);
}
