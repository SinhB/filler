/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:53:50 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/11 03:02:01 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	start(t_filler *filler)
{
	while(1)
	{
		if (!parse_map(filler))
			break;
	}
	return (1);
}

int main(void)
{
	t_filler filler;

	ft_bzero(&filler, sizeof(filler));
	if (!(get_player_number(&filler)))
		return (errors(0));
	if (!(get_map_size(&filler)))
		return (errors(1));
	init_map(&filler);
//	ft_printf("height : %d\n", filler.map.height);
//	ft_printf("width : %d\n", filler.map.width);
	start(&filler);
	free_tab(filler.map.board, filler.map.height);
return (0);
}
