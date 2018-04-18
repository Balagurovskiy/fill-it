/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <obalagur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:12:41 by obalagur          #+#    #+#             */
/*   Updated: 2018/01/12 20:10:31 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_set_position(t_figure *fig, int x, int y)
{
	t_point		*pos_temp;
	t_point		*patt_temp;

	pos_temp = fig->position;
	patt_temp = fig->pattern;
	while (pos_temp && patt_temp)
	{
		pos_temp->x = patt_temp->x + x;
		pos_temp->y = patt_temp->y + y;
		pos_temp = pos_temp->next;
		patt_temp = patt_temp->next;
	}
}

int		ft_on_edge(t_figure *f, size_t size, char xy)
{
	int temp_x;
	int temp_y;
	int	return0;

	return0 = 0;
	temp_y = f->position->y;
	temp_x = f->position->x;
	if (xy == 'x')
	{
		f->position->x = f->position->x + 1;
		f->position->y = 0;
	}
	else if (xy == 'y')
	{
		f->position->x = 0;
		f->position->y = f->position->y + 1;
	}
	ft_set_position(f, f->position->x, f->position->y);
	if (ft_in_bounds(f, size, 0))
		return0 = 1;
	ft_set_position(f, temp_x, temp_y);
	if (return0)
		return (0);
	return (1);
}

void	ft_move(t_figure *curr, t_figure *all, t_point *xy, size_t size)
{
	ft_set_position(curr, xy->x, xy->y);
	if (ft_cmp_position(curr, all) && ft_in_bounds(curr, size, 1))
		return ;
	else
	{
		if (ft_on_edge(curr, size, 'x'))
		{
			if (ft_on_edge(curr, size, 'y'))
			{
				ft_l_reset_pos(curr);
				return ;
			}
			xy->x = 0;
			xy->y = xy->y + 1;
		}
		else
			xy->x = xy->x + 1;
		ft_move(curr, all, xy, size);
	}
}
