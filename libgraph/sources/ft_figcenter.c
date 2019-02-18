/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_figcenter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 23:42:38 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/09 12:43:59 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_vect		*ft_figcenter(t_figure *fig)
{
	t_vect	*vect;

	if (fig->min == NULL)
		fig->min = ft_minvect(fig);
	if (fig->max == NULL)
		fig->max = ft_maxvect(fig);
	vect = ft_vectcomb(0.5, *(fig->max), 0.5, *(fig->min));
	return (vect);
}
