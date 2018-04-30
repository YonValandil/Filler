/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:17:07 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/30 14:12:03 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void 	get_players(t_filler *filler, char **line)
{
	if(ft_strstr(*line, "exec p1"))
	{
		filler->player.nb = 1;
		filler->player.my = 'O';
		filler->player.enemy = 'X';
	}
	else if(ft_strstr(*line, "exec p2"))
	{
		filler->player.nb = 2;
		filler->player.my = 'X';
		filler->player.enemy = 'O';
	}
	else
		exit_error("Error: Player not found\n");
	ft_memdel((void**)line);
}

void 	get_size_map(t_filler *filler, char **line)
{
	int ret;
	char **split;

	split = NULL;
	if(((ret = get_next_line(0, line)) == -1) || (*line == NULL))
		exit_error("Error: get_next_line in get_size_map\n");
	if (!(ft_strstr(*line, "Plateau")))
		exit_error("Error: Plateau not found\n");
	if (!(split = ft_strsplit(*line, ' ')))
		exit_error("Error: ft_strsplit in get_size_map\n");
	if (!(split[2]) && !(split[1]))
		exit_error("Error: slpit[2] or split[1] not exist\n");
	filler->map.w = ft_atoi(split[2]);
	filler->map.h = ft_atoi(split[1]);
	free_split(split);
}

void	get_first_line(char **line)
{
	int ret;

	while (!(ft_strstr(*line, "000 ")))
	{
		ft_memdel((void**)line);
		if(((ret = get_next_line(0, line)) == -1) || (*line == NULL))
			exit_error("Error: get_next_line in get_first_line\n");
	}
}

void 	get_map(t_filler *filler, char **line)
{
	int		x;
	int		y;
	int 	ret;
	char	*true_map_char;

	y = -1;
	true_map_char = NULL;
	get_first_line(line);
	while (++y < filler->map.h)
	{
		x = -1;
		true_map_char = *line + 4;
		while (++x < filler->map.w)
		{
			add_piece(filler, x, y, *true_map_char);
			true_map_char++;
		}
		ft_memdel((void**)line);
		if(((ret = get_next_line(0, line)) == -1) || (*line == NULL))
			exit(EXIT_FAILURE);
	}
}

void 	get_piece(t_filler *filler, char **line)
{
	char *tmp;
	int x;
	int y;

	y = -1;
	piece_length(filler, line);
	while (++y < filler->piece.h)
	{
		ft_memdel((void **)line);
		get_next_line(0, line);//sinon on reste sur les dimensions de la piece
		x = 0;
		tmp = *line;
		while (x < filler->piece.w)
		{
			filler->piece.tab[x][y] = *tmp;
			++x;
			++tmp;
		}
	}
	ft_memdel((void**)line);
}
