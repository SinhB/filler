/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:34:19 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/12 12:26:04 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_tab(char **tab, int y)
{
	int i;

	i = 0;
	while (i < y)
	{
		ft_memdel((void**)&tab[i]);
		i++;
	}
}

void	free_piece(t_filler *filler)
{
	// int i;
	//
	// i = 0;
	// while (i < filler->piece.cnt)
	// {
	// 	ft_memdel((void**)&filler->piece.p[i]);
	// 	i++;
	// }
	free_tab(filler->piece.square, filler->piece.height);
	ft_bzero(&filler->piece, sizeof(filler->piece));
}