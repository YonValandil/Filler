/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:55:41 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/30 16:26:30 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_score(t_filler *filler)
{
	int x;
	int y;

	y = 0;
	while (y < filler->map.h)
	{
		x = 0;
		while (x < filler->map.w)
		{
			if (filler->map.cases[x][y].val == filler->player.enemy)
			{
				if ((y - 1) >= 0)
					filler->map.cases[x][y - 1].score = 2;
				if ((y + 1) < filler->map.h)
					filler->map.cases[x][y + 1].score = 2;
				if (x - 1 >= 0)
					filler->map.cases[x - 1][y].score = 2;
				if (x + 1 < filler->map.w)
					filler->map.cases[x + 1][y].score = 2;
			}
			++x;
		}
		++y;
	}
}

void	check_move(t_filler *filler)
{
	int x;
	int y;
	int score;

	y = 0 - filler->piece.h;
	score = 0;
	reset_move(filler);
	while (y < filler->map.h)
	{
		x = 0 - filler->piece.w;
		while (x < filler->map.w)
		{
			score = check_set_piece(filler, x, y);
			if (score > filler->move.score)
			{
				filler->move.score = score;
				filler->move.x = x;
				filler->move.y = y;
			}
			++x;
		}
		++y;
	}
}

int		check_piece(t_filler *filler, int x, int y)
{
	if (x < 0 || x >= filler->map.w)
		return (0);
	if (y < 0 || y >= filler->map.h)
		return (0);
	if (filler->map.cases[x][y].val == filler->player.enemy)
		return (0);
	if (filler->map.cases[x][y].val == filler->player.my)
		filler->move.weld++;
	return (1);
}

int		check_set_piece(t_filler *filler, int map_x, int map_y)
{
	int x;
	int y;
	int score;

	y = -1;
	score = 0;
	filler->move.weld = 0;
	while (++y < filler->piece.h)
	{
		x = 0;
		while (x < filler->piece.w)
		{
			if (filler->piece.tab[x][y] == '*')
			{
				if (!check_piece(filler, map_x + x, map_y + y))
					return (0);
				score += filler->map.cases[map_x + x][map_y + y].score;
			}
			++x;
		}
	}
	if (filler->move.weld == 1)
		return ((score) ? score : 1);
	return (0);
}

void	play(t_filler *filler)
{
	set_score(filler);
	check_move(filler);
	ft_putnbr(filler->move.y);
	ft_putchar(' ');
	ft_putnbr(filler->move.x);
	ft_putchar('\n');
}
