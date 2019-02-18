/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 00:13:44 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/12 13:18:58 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_exit(int key, t_fdf *fdf)
{
	if (key == KEY_ESC)
		ft_memdel((void **)&fdf);
	exit(1);
	return (0);
}

int		main(int ac, char **av)
{
	int			fd;
	t_fdf		*fdf;
	t_figure	*figure;

	if (ac != 2)
	{
		ft_putstr("Usage: ./fdf [name of file with figure]\n");
		exit(-1);
	}
	fd = open(av[1], O_RDONLY);
	figure = ft_readfile(fd);
	fdf = ft_fdfinit(figure);
	ft_snapshot(fdf, fdf->figure);
	mlx_hook(fdf->win_ptr, KEYPRESS, NOEVENTMASK, ft_keyfunc, fdf);
	mlx_hook(fdf->win_ptr, DESTROYNOTIFY, NOEVENTMASK, ft_exit, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
