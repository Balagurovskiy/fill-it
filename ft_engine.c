/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <obalagur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:12:41 by obalagur          #+#    #+#             */
/*   Updated: 2018/01/13 13:43:54 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_fill_it(t_figure *map)
{
	t_figure	*all;
	t_figure	*first;
	t_point		*xy;
	size_t		size;

	all = map;
	first = map;
	xy = ft_l_point_new(0, 0);
	size = ft_min_size(all);
	ft_fill_all(first, all, xy, size);
	if (xy != NULL)
		ft_l_point_free(&xy);
}

void		ft_fill_all(t_figure *f, t_figure *all, t_point *xy, size_t size)
{
	while (f)
	{
		ft_move(f, all, xy, size);
		if (f->position->x == -6)
		{
			if (f->prev != NULL)
			{
				f = f->prev;
				xy->x = f->position->x + 1;
				xy->y = f->position->y;
			}
			else
			{
				size++;
				xy->x = 0;
				xy->y = 0;
			}
		}
		else
		{
			f = f->next;
			xy->x = 0;
			xy->y = 0;
		}
	}
}

void		ft_end_fillit(t_figure *all)
{
	ft_map_print(all);
	if (all != NULL)
		ft_l_figure_free(&all);
	exit(0);
}
