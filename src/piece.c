/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:00:32 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/27 06:26:52 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

//check piece split

//length piece
	// strstr "Piece"
	// split line for X and Y
	// atoi X, Y
	// free split
void	piece_length(t_filler *filler, char **line)
{
	char **split;
	int ret;

	split = NULL;
	while (ft_strstr(*line, "Piece"))
	{
		ft_memdel((void**)line);
		if(((ret = get_next_line(0, line)) == -1) || (*line == NULL))
			exit(EXIT_FAILURE);
	}
	if (!(split = ft_strsplit(*line, ' ')))
		exit(EXIT_FAILURE);
	if (!(split[2]) && !(split[1]))
		exit(EXIT_FAILURE);
	filler->piece->w = ft_atoi(split[2]);
	filler->piece->h = ft_atoi(split[1]);
	ft_arrdel((void***)&split);
}

void	add_piece(t_filler *filler, int x, int y, char c)
{
	if (c == filler->player->enemy)
		filler->map->cases[y * filler->map->w][x].val = filler->player->enemy;
	else if(c == filler->player->my)
		filler->map->cases[y * filler->map->w][x].val = filler->player->my;
}
