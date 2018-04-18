/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <obalagur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:12:41 by obalagur          #+#    #+#             */
/*   Updated: 2018/01/12 20:10:33 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		*ft_l_empty_points(size_t size)
{
	t_point	*point1;
	t_point	*point;
	size_t	i;

	i = 0;
	point1 = ft_l_point_new(-5, -5);
	point = point1;
	if (size > 1)
	{
		while (i < (size - 1))
		{
			point->next = ft_l_point_new(-5, -5);
			point = point->next;
			i++;
		}
	}
	return (point1);
}

void		ft_zeroing(t_figure *f)
{
	t_figure	*f_tmp;
	t_point		*patt_tmp;
	int			x;
	int			y;

	f_tmp = f;
	if (f)
	{
		while (f_tmp)
		{
			patt_tmp = f_tmp->pattern;
			x = patt_tmp->x;
			y = patt_tmp->y;
			while (patt_tmp)
			{
				patt_tmp->x = patt_tmp->x - x;
				patt_tmp->y = patt_tmp->y - y;
				patt_tmp = patt_tmp->next;
			}
			f_tmp = f_tmp->next;
		}
	}
}

void		ft_set_id(t_figure *f)
{
	t_figure	*f_tmp;
	size_t		id;

	id = 0;
	f_tmp = f;
	while (f_tmp)
	{
		f_tmp->id = id;
		id++;
		f_tmp = f_tmp->next;
	}
}

int			ft_current_size(t_figure *f)
{
	t_figure	*f_tmp;
	t_point		*pos;
	int			max_x;
	int			max_y;

	max_x = 0;
	max_y = 0;
	f_tmp = f;
	while (f_tmp)
	{
		pos = f_tmp->position;
		while (pos)
		{
			if (pos->x > max_x)
				max_x = pos->x;
			if (pos->y > max_y)
				max_y = pos->y;
			pos = pos->next;
		}
		f_tmp = f_tmp->next;
	}
	if (max_x > max_y)
		return (max_x + 1);
	return (max_y + 1);
}

int			ft_min_size(t_figure *f)
{
	t_figure	*f_t;
	int			count;
	int			size;

	f_t = f;
	count = 0;
	size = 0;
	while (f_t)
	{
		count++;
		f_t = f_t->next;
	}
	while ((size * size) <= (count * 4))
		size++;
	size--;
	if ((size * size) < (count * 4))
		size++;
	return (size);
}
