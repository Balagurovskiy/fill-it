/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <obalagur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:13:14 by obalagur          #+#    #+#             */
/*   Updated: 2018/01/13 17:58:39 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_figure	*patterns;
	t_figure	*map;

	ft_valid_argc(argc);
	patterns = ft_read_figures("pattern.fillit");
	ft_valid_struc(argv[1]);
	map = ft_read_figures(argv[1]);
	ft_zeroing(patterns);
	ft_zeroing(map);
	if (!ft_cmp_pattern(map, patterns))
		ft_err_end();
	if (patterns != NULL)
		ft_l_figure_free(&patterns);
	ft_set_id(map);
	ft_fill_it(map);
	ft_end_fillit(map);
	return (0);
}
