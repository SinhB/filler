/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:51:30 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/30 15:30:25 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		init_piece(t_filler *filler)
{
	int i;

	filler->piece.square = (char**)palloc(sizeof(char*) * filler->piece.height);
	i = 0;
	while (i < filler->piece.height)
	{	
		filler->piece.square[i] = (char*)palloc(sizeof(char)
		* filler->piece.width + 1);
		ft_bzero(filler->piece.square[i], filler->piece.width);
		i++;
	}
	return (1);
}

int		init_map(t_filler *filler)
{
	int i;

	filler->map.board = (char**)palloc(sizeof(char*) * filler->map.height);
	i = 0;
	while (i < filler->map.height)
	{
		filler->map.board[i] = (char*)palloc(sizeof(char)
		* filler->map.width + 1);
		ft_bzero(filler->map.board[i], filler->map.width);
		i++;
	}
	return (1);
}
