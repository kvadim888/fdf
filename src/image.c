/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 01:23:33 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/07 20:36:42 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img		*ft_imgnew(void *mlx_ptr, int width, int height)
{
	t_img	*image;

	if ((image = (t_img*)malloc(sizeof(t_img))) == NULL)
		return (NULL);
	if ((image->img = mlx_new_image(mlx_ptr, width, height)) == NULL)
	{
		ft_memdel((void **)&image);
		return (NULL);
	}
	image->height = height;
	image->ptr = mlx_get_data_addr(image->img,\
						&(image->pixel), &(image->width), &(image->endian));
	image->pixel /= 8;
	image->width /= image->pixel;
	return (image);
}

void		ft_imgdel(void *mlx_ptr, t_img *image)
{
	if (mlx_ptr && image)
		mlx_destroy_image(mlx_ptr, image->img);
	ft_memdel((void **)&(image->ptr));
	ft_memdel((void **)&(image));
}

void		ft_imgclear(t_img *image)
{
	int		i;
	int		j;
	int		color;

	color = BACKGROUND;
	j = -1;
	while (++j < image->height)
	{
		i = -1;
		while (++i < image->width)
			ft_pixelset(image, i, j, color - (30 * j / image->height));
	}
}
