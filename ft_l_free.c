/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <obalagur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:12:41 by obalagur          #+#    #+#             */
/*   Updated: 2018/01/12 20:10:32 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_l_point_free(t_point **first)
{
	t_point *next;

	if (first)
	{
		while (*first)
		{
			next = *first;
			*first = (*first)->next;
			free(next);
			next = NULL;
		}
		first = NULL;
	}
}

void		ft_l_figure_free(t_figure **first)
{
	t_figure *next;

	next = *first;
	if (first)
	{
		while (*first)
		{
			ft_l_point_free((&(*first)->position));
			ft_l_point_free((&(*first)->pattern));
			next = *first;
			*first = (*first)->next;
			free(next);
			next = NULL;
		}
	}
}

void		ft_l_reset_pos(t_figure *f)
{
	t_point *f_pos;

	f_pos = f->position;
	while (f_pos)
	{
		f_pos->x = -6;
		f_pos->y = -6;
		f_pos = f_pos->next;
	}
}
