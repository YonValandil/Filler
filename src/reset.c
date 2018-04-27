#include "filler.h"

void	reset_score(t_filler *filler)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < filler->map->h)
	{
		x = 0;
		while (x < filler->map->w)
		{
			(filler->map->cases)[y * filler->map->w][x].score = 0;
			++x;
		}
		++y;
	}
}
