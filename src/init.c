#include "filler.h"

//init_game
	// init dna
 	// get_player
	// get size map
	// get area
void	init_game(t_filler *filler, char **line)
{
	get_players(filler, line);
	get_size_map(filler, line);
	init_map(filler);
}

//create_map
	// t_case =
	// 	int score
	// 	char sign ('O' ou 'X')
	// malloc double tab de t_case
	// store map pointer in dna->area
void 	init_map(t_filler *filler)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!(filler->map->cases = (t_cases**)ft_memalloc(
		(sizeof(t_cases*) * filler->map->w)
		* (sizeof(t_cases) * filler->map->h))))
		exit(EXIT_SUCCESS);
	while (y < filler->map->h)
	{
		x = 0;
		while (x < filler->map->w)
		{
			(filler->map->cases)[y * filler->map->w][x].val = '.';
			(filler->map->cases)[y * filler->map->w][x].score = 0;//?
			++x;
		}
		++y;
	}
}
