/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:51:30 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/12 11:57:59 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		init_piece(t_filler *filler)
{
	int i;
	int j;

	filler->piece.square = (char**)palloc(sizeof(char*) * filler->piece.height);
	i = 0;
	while (i < filler->piece.height)
	{
		j = 0;
		while (j < filler->piece.width)
		{
			filler->piece.square[i] = (char*)palloc(sizeof(char) * filler->piece.width + 1);
			ft_bzero(filler->piece.square[i], filler->piece.width);
			j++;
		}
		i++;
	}
	return (1);
}

int		init_map(t_filler *filler)
{
	int i;
	int j;

	filler->size = filler->map.width * filler->map.height;
	filler->map.board = (char**)palloc(sizeof(char*) * filler->map.height);
	i = 0;
	while (i < filler->map.height)
	{
		j = 0;
		while (j < filler->map.width)
		{
			filler->map.board[i] = (char*)palloc(sizeof(char) * filler->map.width + 1);
			ft_bzero(filler->map.board[i], filler->map.width);
			j++;
		}
		i++;
	}
	filler->init_m = 1;
	return (1);
}