/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:16:22 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/19 16:49:58 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	print_pos(t_filler *filler)
{
	int i;
	int cnt;
	int x;
	int y;

	i = 0;
	while (i < filler->piece.cnt)
	{
		if (is_good(filler, i, &filler->piece.p[i], &filler->point))
		{
			if (filler->piece.p[i].min <= filler->point.min)
				cnt = i;
		}
		i++;
	}
	x = filler->point.x - filler->piece.p[cnt].x;
	y = filler->point.y - filler->piece.p[cnt].y;
	ft_printf("%d %d\n", y, x);
	return (1);
}
