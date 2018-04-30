/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:14:32 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/30 16:20:17 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/include/libft.h"
# include "../libft/include/get_next_line.h"

# define BUF_SIZE 4096
# define BUF_PIECE 256

typedef enum				e_bool
{
	false = 0,
	true
}							t_bool;

typedef struct				s_move
{
	int						x;
	int						y;
	int						score;
	int						weld;

}							t_move;

typedef struct				s_cases
{
	int						x;
	int						y;
	char					val;
	int						score;
}							t_cases;

typedef struct				s_map
{
	t_cases					**cases;
	int						w;
	int						h;
}							t_map;

typedef struct				s_piece
{
	char					tab[BUF_PIECE][BUF_PIECE];
	int						w;
	int						h;
}							t_piece;

typedef struct				s_player
{
	char					my;
	char					enemy;
	int						nb;
}							t_player;

typedef struct				s_filler
{
	t_player				player;
	t_map					map;
	t_piece					piece;
	t_move					move;
}							t_filler;

void						exit_error(const char *s);
void						free_split(char **split);
void						ft_arrdel(void ***arr);
void						init_game(t_filler *filler, char **line);
void						init_map(t_filler *filler);
void						get_players(t_filler *filler, char **line);
void						get_size_map(t_filler *filler, char **line);
void						get_first_line(char **line);
void						get_map(t_filler *filler, char **line);
void						get_piece(t_filler *filler, char **line);
void						reset_score(t_filler *filler);
void						reset_move(t_filler *filler);
void						piece_length(t_filler *filler, char **line);
void						add_piece(t_filler *filler, int x, int y, char c);
int							check_set_piece(t_filler *filler, int x, int y);
int							check_piece(t_filler *filler, int x, int y);
void						play(t_filler *filler);

#endif
