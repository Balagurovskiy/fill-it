/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <obalagur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:23:46 by obalagur          #+#    #+#             */
/*   Updated: 2018/01/13 13:43:06 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		*ft_l_point_new(int const x, int const y)
{
	t_point	*new_node;

	new_node = (t_point*)malloc(sizeof(new_node));
	if (new_node == NULL)
		return (NULL);
	new_node->x = x;
	new_node->y = y;
	new_node->next = NULL;
	return (new_node);
}

t_point		*ft_l_point_add(t_point *first, t_point *new)
{
	t_point *first_tmp;

	if (!new)
		return (NULL);
	if (first)
	{
		first_tmp = first;
		while (first_tmp->next != NULL)
			first_tmp = first_tmp->next;
		first_tmp->next = new;
		return (first);
	}
	else
	{
		first_tmp = ft_l_point_new(new->x, new->y);
		return (first_tmp);
	}
}

t_figure	*ft_l_figure_new(t_point *position, t_point *pattern)
{
	t_figure	*new_node;

	new_node = (t_figure*)malloc(sizeof(new_node));
	if (new_node == NULL)
		return (NULL);
	if (position && pattern)
	{
		new_node->position = (t_point*)malloc(sizeof(t_point));
		if (new_node->position == NULL)
			return (NULL);
		new_node->position = position;
		new_node->pattern = (t_point*)malloc(sizeof(t_point));
		if (new_node->pattern == NULL)
			return (NULL);
		new_node->pattern = pattern;
		new_node->next = NULL;
		new_node->prev = NULL;
		return (new_node);
	}
	return (NULL);
}

t_figure	*ft_l_figure_add(t_figure *first, t_figure *new)
{
	t_figure *first_tmp;

	if (!new)
		return (NULL);
	if (first)
	{
		first_tmp = first;
		while (first_tmp->next != NULL)
			first_tmp = first_tmp->next;
		first_tmp->next = new;
		new->next = NULL;
		new->prev = first_tmp;
		return (first);
	}
	else
	{
		first_tmp = ft_l_figure_new(new->position, new->pattern);
		return (first_tmp);
	}
}
