/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:53:50 by yabecret          #+#    #+#             */
/*   Updated: 2019/05/10 15:55:52 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	start(t_filler *filler)
{
	int end;

	end = 1;
	if (!(get_map_size(filler)))
		return (errors(filler, 1));
	filler->size = filler->map.width * filler->map.height;
	filler->point.min = filler->size;
	if (!init_map(filler))
		return (errors(filler, 7));
	while (end)
	{
		if (!parse_map(filler))
			break ;
		if (!parse_piece(filler))
			break ;
		end = algo(filler);
	}
	return (1);
}

int	main(void)
{
	t_filler filler;

	ft_bzero(&filler, sizeof(filler));
	if (!(get_player_number(&filler, 0)))
		return (errors(&filler, 0));
	start(&filler);
	return (0);
}
