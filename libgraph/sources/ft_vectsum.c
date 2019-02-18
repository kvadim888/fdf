/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectsum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 22:43:34 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/09 13:23:39 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_vectsum(t_vect *v1, t_vect v2)
{
	t_vect *tmp;

	tmp = ft_vectcomb(1, *v1, 1, v2);
	ft_vectcoord(v1, tmp->x, tmp->y, tmp->z);
	ft_memdel((void**)&tmp);
}
