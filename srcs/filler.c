/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:53:50 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/15 18:31:19 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	start(t_filler *filler)
{
	int end;

	end = 1;
	if (!(get_map_size(filler)))
		return (errors(filler, 1));
	init_map(filler);
	while (end)
	{
	//	ft_dprintf(2, "parse map..\n");
		if (!parse_map(filler))
			break;
	//	ft_dprintf(2, "parse piece..\n");
		if (!parse_piece(filler))
			break;
	//	ft_dprintf(2, "algo ..\n");
		end = algo(filler);
	//	ft_dprintf(2, "algo done\n");
	}
	free_struct(filler);
	return (1);
}

int main(void)
{
	t_filler filler;

	ft_bzero(&filler, sizeof(filler));
	if (!(get_player_number(&filler)))
		return (errors(&filler, 0));
	start(&filler);
return (0);
}
