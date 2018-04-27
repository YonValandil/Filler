#include "filler.h"
//xy?

//free_tab
void	ft_arrdel(void ***arr)
{
	char **tmp;

	if (arr && *arr)
	{
		tmp = *((char ***)arr);
		while (*tmp)
		{
			ft_memdel((void **)tmp);
			++tmp;
		}
		free(*arr);
		*arr = NULL;
	}
}

//error_func
void	exit_error(const char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

int		main(void)
{
	t_filler filler;
	int ret;
	char *line;

	line = NULL;
	bzero(&filler, sizeof(t_filler)); //?
	while ((ret = get_next_line(0, &line)) > 0)
	{
		dprintf(2,"\n line = %s", line);

		// if first time init game
		if (!(filler.map->cases))
			init_game(&filler, &line);

		//reset score in map
		reset_score(&filler);

		//parse map
		get_map(&filler, &line);

		//pars piece
		get_piece(&filler, &line);

		//play
		// play(&filler);
	}
	return (EXIT_SUCCESS);
}
