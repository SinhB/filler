/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:53:19 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/10 18:11:08 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

# include "../libft/includes/libft.h"

# define P_X	01111000	// x
# define P_O	01101111	// o
# define G_X	01011000	// X
# define G_O	01001111	// O

typedef struct	s_point
{
	int			x;
	int			y;
	int			min_dist;
	int			good;
}				t_point;

typedef struct	s_piece
{
	int			width;
	int			height;
	int			x;
	int			y;
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
	int			p_nb;
	int			size;
	int			init;
	t_map		map;
	t_piece		piece;
}				t_filler;

int				get_map_size(t_filler *filler);
int				get_player_number(t_filler *filler);
int				init_map(t_filler *filler);
int				parse_map(t_filler *filler);
int				errors(int i);

void			free_tab(char **tab, int y);

#endif
