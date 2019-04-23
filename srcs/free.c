/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:34:19 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/23 18:28:59 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		filler_end(t_filler *filler, int end)
{
	if (end == 1)
	{
		print_pos(filler);
		free_piece(&filler->piece);
		filler->point.x = 0;
		filler->point.y = 0;
		filler->point.min = filler->size;
	}
	else
	{
		free_struct(filler);
		ft_printf("0 0\n");
	}
	return (end);
}

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->height)
		free(map->board[i++]);
	free(map->board);
	map->board = NULL;
}

void	free_piece(t_piece *piece)
{
	int i;

	i = 0;
	while (i < piece->height)
		free(piece->square[i++]);
	free(piece->square);
	free(piece->p);
	piece->p = NULL;
	piece->square = NULL;
	piece->cnt = 0;
	piece->width = 0;
	piece->height = 0;
}

void	free_struct(t_filler *filler)
{
	free(filler->m_features);
	free_map(&filler->map);
	free_piece(&filler->piece);
}
