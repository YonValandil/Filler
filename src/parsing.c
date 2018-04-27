/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:17:07 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/27 06:28:54 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

//get player
	// if strstr exec p1
	// 	dna.player = 1
	// else
	// 	dna. player = 2
void 	get_players(t_filler *filler, char **line)
{
	if(ft_strstr("exec p1", *line))
	{
		filler->player->nb = 1;
		filler->player->my = 'O';
		filler->player->enemy = 'X';
	}
	else if(ft_strstr("exec p2", *line))
	{
		filler->player->nb = 2;
		filler->player->my = 'X';
		filler->player->enemy = 'O';
	}
	else
		exit(EXIT_FAILURE);
	ft_memdel((void**)line);
}

//get map size
	// strstr Plateau
	// split string
	// atoi on 2 et 1
	// free split
void 	get_size_map(t_filler *filler, char **line)
{
	int ret;
	char **split;

	split = NULL;
	if(((ret = get_next_line(0, line)) == -1) || (*line == NULL))
		exit(EXIT_FAILURE);
	if (!(ft_strstr(*line, "Plateau")))
		exit(EXIT_FAILURE);
	if (!(split = ft_strsplit(*line, ' ')))
		exit(EXIT_FAILURE);
	if (!(split[2]) && !(split[1]))
		exit(EXIT_FAILURE);
	filler->map->w = ft_atoi(split[2]);
	filler->map->h = ft_atoi(split[1]);
	ft_arrdel((void***)&split);
}

void	get_first_line(char **line)
{
	int ret;

	while (!(ft_strstr(*line, "000 ")))
	{
		ft_memdel((void**)line);
		if(((ret = get_next_line(0, line)) == -1) || (*line == NULL))
			exit(EXIT_FAILURE);
	}
}

// parse map
	// 	strstr "000"
	// 	GNL while y < dna.map->h
	// 	line + 4 for find first sign of map
	//	ft_memdel gnl
void 	get_map(t_filler *filler, char **line)
{
	int		x;
	int		y;
	int 	ret;
	char	*true_map_char;

	y = -1;
	true_map_char = NULL;
	get_first_line(line);
	while (++y < filler->map->h)
	{
		x = -1;
		true_map_char = *line + 4;
		while (++x < filler->map->w)
		{
			add_piece(filler, x, y, *true_map_char);
			true_map_char++;
		}
		ft_memdel((void**)line);
		if(((ret = get_next_line(0, line)) == -1) || (*line == NULL))
			exit(EXIT_FAILURE);
	}
}

//pars piece
	//length piece if 0 exit
	//fill piece remplir
void 	get_piece(t_filler *filler, char **line)
{
	char *tmp;
	int ret;
	int x;
	int y;

	y = -1;
	piece_length(filler, line);
	while (++y < filler->map->h)
	{
		x = -1;
		tmp = *line;
		while (++x < filler->map->w)
		{
			filler->piece->tab[x][y] = *tmp;
			++tmp;
		}
		ft_memdel((void**)line);
		if(((ret = get_next_line(0, line)) == -1) || (*line == NULL))
			exit(EXIT_FAILURE);
	}
}
