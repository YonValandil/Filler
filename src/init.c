/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:14:50 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/30 16:21:38 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_game(t_filler *filler, char **line)
{
	get_players(filler, line);
	get_size_map(filler, line);
	init_map(filler);
}

void	init_map(t_filler *filler)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!(filler->map.cases = (t_cases**)ft_memalloc((sizeof(t_cases*) *
		filler->map.w))))
		exit(EXIT_FAILURE);
	while (x < filler->map.w)
	{
		y = 0;
		if (!(filler->map.cases[x] = (t_cases*)ft_memalloc((sizeof(t_cases) *
			filler->map.h))))
			exit(EXIT_FAILURE);
		while (y < filler->map.h)
		{
			(filler->map.cases)[x][y].val = '.';
			(filler->map.cases)[x][y].score = 0;
			++y;
		}
		++x;
	}
}
