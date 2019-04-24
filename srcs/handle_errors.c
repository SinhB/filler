/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:52:59 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/24 18:03:59 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	errors(t_filler *filler, int i)
{
	if (i == 0)
		ft_dprintf(2, "usage : $$$ exec pPLAYER_NUMBER : [PLAYER_NAME]\n");
	if (i == 1)
		ft_dprintf(2, "usage : Plateau MAP_ROW MAP_COL:\n");
	if (i == 2)
		ft_dprintf(2, "usage : Piece PIECE_ROW PIECE_COL:\n");
	if (i == 3)
		ft_dprintf(2, "usage : Plateau size can't change during game.\n");
	if (i == 4)
		ft_dprintf(2, "Piece format error.\n");
	if (i == 5)
		ft_dprintf(2, "Map format error.\n");
	if (i == 6)
		ft_dprintf(2, "First map line error.\n");
	if (i == 2 || i == 3 || i == 4 || i == 5 || i == 6)
		free_struct(filler);
	return (0);
}
