/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:48:12 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/12 12:10:43 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_piece(t_filler *filler)
{
	int i;

	i = 0;
	while (i < filler->piece.height)
	{
		ft_dprintf(2, "%s\n", filler->piece.square[i]); //fd = 2 to print without affecting VM input -> only for testing
		i++;
	}
}

int		parse_piece(t_filler *filler)
{
	if (!get_piece_size(filler))
		return (errors(2));
	init_piece(filler);
	fill_piece(filler);
	print_piece(filler);
	return (1);
}
