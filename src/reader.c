/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 01:49:53 by vkryvono          #+#    #+#             */
/*   Updated: 2018/09/12 12:56:28 by vkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void			ft_error(int fd, char *msg)
{
	if (fd > 2)
		close(fd);
	if (msg)
	{
		ft_putstr_fd("fdf: ", 2);
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	exit(-1);
}

static int		ft_validz(char *str)
{
	int i;
	int k;

	i = 0;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (i);
	if ((str[i] != '\0') && ((str[i] != ',') || (i == 0)))
		return (0);
	i++;
	if ((str[i] == '\0') || (str[i] != '0'))
		return (0);
	i++;
	if ((str[i] == '\0') || (str[i] != 'x'))
		return (0);
	i++;
	k = i;
	while (((i - k) < 6) && (str[i] != '\0') && (ft_isdigit(str[i])
			|| ((str[i] >= 'A') && (str[i] <= 'F'))
			|| ((str[i] >= 'a') && (str[i] <= 'f'))))
		i++;
	return ((((i - k) <= 6) && (str[i] == '\0')) ? i : 0);
}

static char		**ft_readline(char *str)
{
	static int	length = -1;
	char		**buff;
	int			i;

	buff = ft_strsplit(str, ' ');
	if ((length >= 0) && (length != ft_strsplitlen(buff)))
		ft_error(0, "invalid  map");
	else
		length = ft_strsplitlen(buff);
	i = 0;
	if (!buff || buff[0] == '\0')
		ft_error(0, "invalid  map");
	while (buff[i])
	{
		if (ft_validz(buff[i]) == 0)
			ft_error(0, "invalid  map");
		i++;
	}
	return (buff);
}

static t_figure	*ft_addvectors(t_list *lst)
{
	char		**buff;
	t_figure	*fig;
	int			i;
	int			j;

	if (!lst)
		ft_error(0, "empty map");
	if (!(fig = ft_fignew(ft_wordcounter(lst->content, ' '), ft_lstlen(lst))))
		ft_error(0, "allocation error");
	i = -1;
	while (lst && (++i < fig->ymax))
	{
		buff = ft_readline(lst->content);
		j = -1;
		while (++j < fig->xmax)
		{
			if (!(fig->vect[i][j] = ft_vectnew(j, i, ft_atoi(buff[j]))))
				ft_error(0, "allocation error");
			ft_readcolor(fig->vect[i][j], ft_strchr(buff[j], ','));
			free(buff[j]);
		}
		free(buff);
		lst = lst->next;
	}
	return (fig);
}

t_figure		*ft_readfile(int fd)
{
	t_list		*lst;
	char		*line;
	int			status;
	t_figure	*figure;

	if (fd < 0)
		ft_error(fd, strerror(errno));
	line = NULL;
	lst = NULL;
	while ((status = get_next_line(fd, &line)) > 0)
	{
		lst = ft_lstappend(lst, ft_lstnew(line, ft_strlen(line) + 1));
		free(line);
	}
	if (status < 0)
		ft_error(fd, strerror(errno));
	if (ft_strlen(line) > 0)
		lst = ft_lstappend(lst, ft_lstnew(line, ft_strlen(line) + 1));
	free(line);
	close(fd);
	figure = ft_addvectors(lst);
	ft_lstdel(&lst, ft_lstrm);
	figure->min = ft_minvect(figure);
	figure->max = ft_maxvect(figure);
	return (figure);
}
