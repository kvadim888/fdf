/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectcoord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:32:16 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/07 16:34:51 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_vectcoord(t_vect *vect, double x, double y, double z)
{
	if (!vect)
		return ;
	vect->x = x;
	vect->y = y;
	vect->z = z;
}
