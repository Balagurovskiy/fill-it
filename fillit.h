/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <obalagur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:52:14 by obalagur          #+#    #+#             */
/*   Updated: 2018/01/13 16:36:38 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_point
{
	int				x;
	int				y;
	struct s_point	*next;
}					t_point;

typedef struct		s_figure
{
	t_point			*position;
	t_point			*pattern;
	size_t			id;
	struct s_figure	*prev;
	struct s_figure	*next;
}					t_figure;

t_point				*ft_l_point_new(int const x, int const y);
t_figure			*ft_l_figure_new(t_point *curr_pos, t_point *pattern);
t_point				*ft_l_point_add(t_point *first, t_point *new);
t_figure			*ft_l_figure_add(t_figure *first, t_figure *new);
void				ft_l_point_free(t_point **first);
void				ft_l_figure_free(t_figure **first);
void				ft_l_reset_pos(t_figure *f);
void				ft_iterate(int *x, int *y, char buff);
t_point				*ft_copy_point(int x, int y, t_point *first);
void				ft_copy_figure(t_point **p, t_point points,
						t_figure **figure, size_t i);
t_point				*ft_read_points(char *file);
t_figure			*ft_read_figures(char *file);
int					ft_cmp_pattern(t_figure *target, t_figure *source);
int					ft_find_pattern(t_point *point, t_figure *figure);
int					ft_cmp_position(t_figure *target, t_figure *first);
int					ft_find_position(t_point *target, t_point *first);
void				ft_set_position(t_figure *fig, int x, int y);
int					ft_on_edge(t_figure *f, size_t size, char xy);
void				ft_move(t_figure *curr, t_figure *all, t_point *xy,
						size_t size);
void				ft_set_id(t_figure *f);
t_point				*ft_l_empty_points(size_t size);
void				ft_zeroing(t_figure *f);
int					ft_current_size(t_figure *f);
int					ft_min_size(t_figure *f);
void				ft_valid_input(int fd, int x, int y, char *buff);
void				ft_valid_argc(int argc);
void				ft_valid_struc(char *file);
int					ft_in_bounds(t_figure *f, size_t size, int minus_flag);
void				ft_err_end();
void				ft_fill_it(t_figure *map);
void				ft_fill_all(t_figure *f, t_figure *all, t_point *xy,
							size_t size);
void				ft_end_fillit(t_figure *all);
void				ft_str_print(char *s);
int					ft_is_figure(int x, int y, t_figure *map);
void				ft_map_print(t_figure	*map);
void				ft_print_letter(size_t id);

#endif
