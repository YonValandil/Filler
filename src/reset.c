/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:15:20 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/30 16:15:22 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	reset_score(t_filler *filler)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < filler->map.h)
	{
		x = 0;
		while (x < filler->map.w)
		{
			(filler->map.cases)[x][y].score = 0;
			++x;
		}
		++y;
	}
}

void	reset_move(t_filler *filler)
{
	filler->move.score = 0;
	filler->move.x = 0;
	filler->move.y = 0;
}
