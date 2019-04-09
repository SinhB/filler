/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:53:19 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/09 17:35:33 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

# include "../libft/includes/libft.h"

typedef struct	s_piece
{

}				t_piece;

typedef struct	s_map
{
	int			x;
	int			y;
}				t_map;


typedef struct	s_filler
{
	int			p_nb;
	t_map		map;
}				t_filler;

int				get_map_size(t_filler *filler);
int				get_player_number(t_filler *filler);
int				errors(int i);

#endif
