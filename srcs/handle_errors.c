/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:52:59 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/09 17:39:26 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	errors(int i)
{
	if (i == 0)
		ft_dprintf(2, "usage : $$$ exec pPLAYER_NUMBER : [PLAYER_NAME]\n");
	if (i == 1)
		ft_dprintf(2, "usage : Plateau MAP_ROW MAP_COL:\n");
	return (0);
}
