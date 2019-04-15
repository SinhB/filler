/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:53:19 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/15 21:47:36 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

# include "../libft/includes/libft.h"
# include <math.h>

# define P_X	01111000	// x
# define P_O	01101111	// o
# define G_X	01011000	// X
# define G_O	01001111	// O

typedef struct	s_point
{
	int			i;
	int			x;
	int			y;
	double		min;
	int			good;
}				t_point;

typedef struct	s_piece
{
	int			width;
	int			height;
	int			cnt;
	t_point		*p;
	char 		**square;
}				t_piece;

typedef struct	s_map
{
	int			width;
	int			height;
	int			size;
	char 		**board;
}				t_map;


typedef struct	s_filler
{
	char		me;
	char		ad;
	int			size;
	int			init_m;
	char		*m_features;
	t_map		map;
	t_piece		piece;
	t_point		point;
}				t_filler;

/*
**------------------------------------- ALGO -----------------------------------
*/

int				algo(t_filler *filler);

/*
**----------------------------------- GET_DATA ---------------------------------
*/

int				get_map_size(t_filler *filler);
int				get_piece_size(t_filler *filler);
int				get_player_number(t_filler *filler);

/*
**------------------------------------ INIT ------------------------------------
*/

int				init_map(t_filler *filler);
int				init_piece(t_filler *filler);

/*
**---------------------------------- PARSE_MAP ---------------------------------
*/

int				parse_m_features(t_filler *filler);
int				parse_map(t_filler *filler);

/*
**---------------------------------- FILL_MAP ----------------------------------
*/

int				fill_map(t_filler *filler);

/*
**---------------------------------- PARSE_PIECE -------------------------------
*/

int				parse_p_features(t_filler *filler);
int				parse_piece(t_filler *filler);

/*
**---------------------------------- FILL_PIECE --------------------------------
*/

void			palloc_case(t_filler *filler);
void			get_point_pos(t_filler *filler);
int				fill_piece(t_filler *filler);

/*
**------------------------------------ ERRORS ----------------------------------
*/

int				errors(t_filler *filler, int i);

/*
**------------------------------------ CHECK -----------------------------------
*/

int				check_features(t_filler *filler, char *line, int i);
int				check_p_line(t_filler *filler, char *line);
int				check_p_pos(t_filler *filler, t_point *tracker);
int				is_good(t_filler *filler, int j, t_point *p, t_point *t);

/*
**------------------------------------ FREE ------------------------------------
*/

void			*free_tab(char ***tab);
void			free_piece(t_piece *piece);
void			free_map(t_map *map);
void			free_struct(t_filler *filler);

#endif
