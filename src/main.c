#include "filler.h"

void	free_split(char **split)
{
	ft_memdel((void**)&split[0]);
	ft_memdel((void**)&split[1]);
	ft_memdel((void**)&split[2]);
	ft_memdel((void**)&split);
}

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
	bzero(&filler, sizeof(t_filler));
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!(filler.map.cases))
			init_game(&filler, &line);

		reset_score(&filler);
		get_map(&filler, &line);
		get_piece(&filler, &line);
		play(&filler);
	}
	return (EXIT_SUCCESS);
}
