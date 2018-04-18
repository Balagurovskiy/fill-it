/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <obalagur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:12:41 by obalagur          #+#    #+#             */
/*   Updated: 2018/01/13 17:27:28 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_valid_input(int fd, int x, int y, char *buff)
{
	if (fd < 0)
		ft_err_end();
	if ((*buff != '#') && (*buff != '.') && (*buff != '\n'))
		ft_err_end();
	if (x > 4 || y > 4)
		ft_err_end();
	if (*buff == '\n' && ((x != 4) && (y < 4)))
		ft_err_end();
}

void		ft_err_end(void)
{
	ft_str_print("error");
	exit(0);
}

void		ft_valid_struc(char *file)
{
	int			fd;
	char		buffer;
	int			sl_n;

	sl_n = 0;
	fd = open(file, O_RDONLY);
	if (read(fd, &buffer, 1) < 0)
		ft_err_end();
	while (read(fd, &buffer, 1))
	{
		if (buffer == '\n')
			sl_n++;
		else
			sl_n = 0;
	}
	if (sl_n > 1)
		ft_err_end();
	close(fd);
}

void		ft_valid_argc(int argc)
{
	if (argc != 2)
	{
		ft_str_print("usage: ./fillit input_file");
		exit(0);
	}
}

int			ft_in_bounds(t_figure *f, size_t size, int minus_flag)
{
	t_point *f_pos;
	int		s;

	f_pos = f->position;
	s = (int)size;
	while (f_pos)
	{
		if (minus_flag)
		{
			if ((f_pos->x < 0) || (f_pos->y < 0))
				return (0);
		}
		if (f_pos->x >= s || f_pos->y >= s)
			return (0);
		f_pos = f_pos->next;
	}
	return (1);
}
