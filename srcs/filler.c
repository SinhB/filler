/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:53:50 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/13 20:47:32 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	start(t_filler *filler)
{
	while(1)
	{
		if (!parse_map(filler))
			break;
		ft_dprintf(2, "map done\n");
		if (!parse_piece(filler))
			break;
		ft_dprintf(2, "piece done\n");
		algo(filler);
		ft_dprintf(2, "algo done\n");
	}
	return (1);
}

int main(void)
{
	t_filler filler;

	ft_bzero(&filler, sizeof(filler));
	if (!(get_player_number(&filler)))
		return (errors(&filler, 0));
	start(&filler);
	free_struct(&filler);
return (0);
}
