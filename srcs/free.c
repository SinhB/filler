/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:34:19 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/13 22:14:27 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	*free_tab(char ***tab)
{
	int i;

	if (!(*tab))
		return ((void *)0);
	i = 0;
	while ((*tab)[i])
	{
		if ((*tab)[i])
		{
			free((*tab)[i]);
			(*tab)[i++] = (void *)0;
		}
		else
			i++;
	}
	free(*tab);
	*tab = (void *)0;
	return ((void *)0);
}

void	free_map(t_map *map)
{
	ft_bzero(&map, sizeof(t_map));
	free_tab(&map->board);
	free(map);
}

void	free_point(t_point *point)
{
	ft_dprintf(2, "free point....\n");
	ft_bzero(&point, sizeof(t_point));
	//free(&point);
	ft_dprintf(2, "free point done....\n");
}

void	free_piece(t_piece *piece)
{
	int i;

	i = 0;
	ft_dprintf(2, "free piece....\n");
	piece->cnt = 0;
	piece->width = 0;
	piece->height = 0;
	free_point(piece->p);
	free(piece->square);
	//free(&piece);
}

void	free_struct(t_filler *filler)
{
	free(filler->m_features);
	free_map(&filler->map);
	free_piece(&filler->piece);
	free(filler);
}
