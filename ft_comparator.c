/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comparator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <obalagur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:12:41 by obalagur          #+#    #+#             */
/*   Updated: 2018/01/03 19:24:48 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_pattern(t_point *point, t_figure *figure)
{
	t_figure	*figure_tmp;
	t_point		*figure_p;
	t_point		*p_tmp;

	figure_tmp = figure;
	while (figure_tmp)
	{
		figure_p = figure_tmp->pattern;
		p_tmp = point;
		while ((figure_p->x == p_tmp->x) && (figure_p->y == p_tmp->y))
		{
			figure_p = figure_p->next;
			p_tmp = p_tmp->next;
			if (!figure_p)
				return (1);
		}
		figure_tmp = figure_tmp->next;
	}
	return (0);
}

int		ft_cmp_pattern(t_figure *target, t_figure *source)
{
	t_figure	*target_temp;
	t_figure	*source_temp;
	t_point		*target_p;

	source_temp = source;
	target_temp = target;
	while (target_temp)
	{
		target_p = target_temp->pattern;
		if (!ft_find_pattern(target_p, source_temp))
			return (0);
		target_temp = target_temp->next;
	}
	return (1);
}

int		ft_find_position(t_point *target, t_point *first)
{
	t_point		*t_pos;
	t_point		*f_pos;

	t_pos = target;
	while (t_pos)
	{
		f_pos = first;
		while (f_pos)
		{
			if ((t_pos->x == f_pos->x) && (t_pos->y == f_pos->y))
				return (0);
			f_pos = f_pos->next;
		}
		t_pos = t_pos->next;
	}
	return (1);
}

int		ft_cmp_position(t_figure *target, t_figure *first)
{
	t_figure	*first_temp;

	first_temp = first;
	while (first_temp)
	{
		if (first_temp->id != target->id)
		{
			if (!ft_find_position(target->position, first_temp->position))
				return (0);
		}
		first_temp = first_temp->next;
	}
	return (1);
}
