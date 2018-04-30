/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:00:32 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/30 14:12:39 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	piece_length(t_filler *filler, char **line)
{
	char **split;

	split = NULL;
	if (!(split = ft_strsplit(*line, ' ')))
		exit(EXIT_FAILURE);
	if (!(split[2]) && !(split[1]))
		exit(EXIT_FAILURE);
	filler->piece.w = ft_atoi(split[2]);
	filler->piece.h = ft_atoi(split[1]);
	free_split(split);
}

void	add_piece(t_filler *filler, int x, int y, char c)
{
	if (c == filler->player.enemy)
		filler->map.cases[x][y].val = filler->player.enemy;
	else if(c == filler->player.my)
		filler->map.cases[x][y].val = filler->player.my;
}
