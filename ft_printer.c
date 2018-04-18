/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <obalagur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:12:41 by obalagur          #+#    #+#             */
/*   Updated: 2018/01/11 18:30:34 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_map_print(t_figure *map)
{
	int			size;
	int			i;
	int			j;
	size_t		id;

	size = ft_current_size(map);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			id = (size_t)ft_is_figure(j, i, map);
			if (id < 100)
				ft_print_letter(id);
			else
				write(1, ".", 1);
			j++;
			if (j == size)
				write(1, "\n", 1);
		}
		i++;
	}
}

void	ft_print_letter(size_t id)
{
	char		lett;

	lett = 'A' + id;
	write(1, &lett, 1);
}

int		ft_is_figure(int x, int y, t_figure *map)
{
	t_figure	*map_t;
	t_point		*pos;

	map_t = map;
	while (map_t)
	{
		pos = map_t->position;
		while (pos)
		{
			if ((pos->x == x) && (pos->y == y))
				return (map_t->id);
			pos = pos->next;
		}
		map_t = map_t->next;
	}
	return (100);
}

void	ft_str_print(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
}
