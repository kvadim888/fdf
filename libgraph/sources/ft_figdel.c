/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_figdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 18:49:38 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/05 02:12:58 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_figdel(t_figure *figure)
{
	int		i;
	int		j;

	if (!figure)
		return ;
	if (figure->vect)
	{
		i = -1;
		while (++i < figure->ymax)
		{
			if (figure->vect[i])
			{
				j = -1;
				while (++j < figure->xmax)
					if (figure->vect[i][j])
						free(figure->vect[i][j]);
				free(figure->vect[i]);
			}
		}
		free(figure->vect);
	}
	free(figure);
}
