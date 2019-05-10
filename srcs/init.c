/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:51:30 by yabecret          #+#    #+#             */
/*   Updated: 2019/05/10 12:57:11 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		init_piece(t_filler *filler)
{
	int i;

	if (!(filler->piece.square = (char**)malloc(sizeof(char*)
		* filler->piece.height)))
		return (0);
	i = 0;
	while (i < filler->piece.height)
	{
		if (!(filler->piece.square[i] = (char*)malloc(sizeof(char)
		* filler->piece.width + 1)))
			return (free_index(filler, i, 0));
		ft_bzero(filler->piece.square[i], filler->piece.width);
		i++;
	}
	return (1);
}

int		init_map(t_filler *filler)
{
	int i;

	if (!(filler->map.board = (char**)malloc(sizeof(char*)
		* filler->map.height)))
		return (0);
	i = 0;
	while (i < filler->map.height)
	{
		if (!(filler->map.board[i] = (char*)malloc(sizeof(char)
		* filler->map.width + 1)))
			return (free_index(filler, i, 1));
		ft_bzero(filler->map.board[i], filler->map.width);
		i++;
	}
	return (1);
}
