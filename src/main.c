#include "filler.h"


//init_game
	// init dna
 	// get_player
	// get size map
	// get area

//create_map
	// t_case =
	// 	int score
	// 	char sign ('O' ou 'X')
	// malloc double tab de t_case
	// store map pointer in dna->area


int		main(void)
{
	int ret;
	char *line;

	line = NULL;
	while ((ret = get_next_line(0, &line)))
	{
		dprintf(2,"\n line = %s", line);

		// if first time init game
		// else reset map

		//reset map == reset score in map

		//pars map or init map

		//pars piece

		//play




	}
	return (EXIT_SUCCESS);
}
