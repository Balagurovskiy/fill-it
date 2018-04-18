/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <obalagur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:13:14 by obalagur          #+#    #+#             */
/*   Updated: 2018/01/13 17:58:38 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_iterate(int *x, int *y, char buff)
{
	if (buff != '\n')
		(*x)++;
	else
	{
		if (*x == 0)
			*y = 0;
		else
		{
			*x = 0;
			(*y)++;
		}
	}
}

t_point			*ft_copy_point(int x, int y, t_point *first)
{
	t_point	*point;

	point = ft_l_point_new(x, y);
	return (ft_l_point_add(first, point));
}

t_point			*ft_read_points(char *file)
{
	int			fd;
	char		buffer;
	int			x;
	int			y;
	t_point		*points;

	x = 0;
	y = 0;
	points = NULL;
	fd = open(file, O_RDONLY);	
	while (read(fd, &buffer, 1))
	{
		ft_valid_input(fd, x, y, &buffer);
		if (buffer == '#')
			points = ft_copy_point(x, y, points);
		else if (y == 4 && points == NULL)
			ft_err_end();
		ft_iterate(&x, &y, buffer);
	}
	if (buffer != '\n' && y != 4)
		ft_err_end();
	close(fd);
	return (points);
}

void			ft_copy_figure(t_point **p, t_point points,
							t_figure **figure, size_t i)
{
	if (i < 4)
	{
		(*p)->x = points.x;
		(*p)->y = points.y;
		(*p) = (*p)->next;
	}
	if ((i == 3) && (points.next != NULL))
	{
		(*figure)->next = ft_l_figure_new(ft_l_empty_points(4),
											ft_l_empty_points(4));
		(*figure)->next->prev = (*figure);
		(*figure) = (*figure)->next;
		(*p) = (*figure)->pattern;
	}
}

t_figure		*ft_read_figures(char *file)
{
	t_figure	*figures;
	t_point		*points;
	t_figure	*figure;
	t_point		*p;
	size_t		i;

	i = 0;
	points = ft_read_points(file);
	figures = ft_l_figure_new(ft_l_empty_points(4),
								ft_l_empty_points(4));
	figure = figures;
	p = figure->pattern;
	while (points)
	{
		ft_copy_figure(&p, *points, &figure, i);
		points = points->next;
		i++;
		if (i == 4)
			i = 0;
	}
	ft_l_point_free(&points);
	return (figures);
}
