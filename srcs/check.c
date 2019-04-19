/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:28:44 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/19 16:50:58 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_good(t_filler *filler)
{
	int i;

	i = 0;
	while (i < filler->piece.cnt)
	{
		if (filler->piece.p[i].good)
			return (1);
		i++;
	}
	return (0);
}

int	is_good(t_filler *filler, int j, t_point *p, t_point *t)
{
	int i;
	int x1;
	int y1;

	i = 0;
	while (i < filler->piece.cnt)
	{
		y1 = (filler->piece.p[i].y - p->y + t->y);
		x1 = (filler->piece.p[i].x - p->x + t->x);
		if (i == j)
			i++;
		else
		{
			if ((y1 < 0) || (y1 >= filler->map.height) || (x1 < 0) || (x1 >= filler->map.width))
				return (0);
			if (filler->map.board[y1][x1] != '.')
				return (0);
			i++;
		}
	}
	return (1);
}

int	check_p_pos(t_filler *filler, t_point *tracker)
{
	int i;
	t_point p;

	i = 0;
	while (i < filler->piece.cnt)
	{
		p.x = filler->piece.p[i].x;
		p.y = filler->piece.p[i].y;
		filler->piece.p[i].good = is_good(filler, i, &p, tracker);
		i++;
	}
	return (check_good(filler));
}
