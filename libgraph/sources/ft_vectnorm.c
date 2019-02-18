/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectnorm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 22:00:57 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/07 14:08:52 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_vect	*ft_vectnorm(t_vect *vect, int mode)
{
	double	module;
	t_vect	*new;

	if (vect == NULL)
		return (NULL);
	if (mode == 1)
		new = vect;
	else
	{
		if ((new = ft_vectnew(vect->x, vect->y, vect->z)) == NULL)
			return (NULL);
		new->color = vect->color;
	}
	module = ft_vectmodule(*new);
	new->x = new->x / module;
	new->y = new->y / module;
	new->z = new->z / module;
	return (new);
}
