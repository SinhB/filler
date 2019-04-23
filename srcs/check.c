/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:28:44 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/23 18:10:58 by yabecret         ###   ########.fr       */
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

int	check_edge(t_filler *filler, t_point *p)
{
	if ((p->y - 1 > 0) && filler->map.board[p->y - 1][p->x] == '.')
		return (1);
	if ((p->y + 1 < filler->map.height)
		&& filler->map.board[p->y + 1][p->x] == '.')
		return (1);
	if ((p->x + 1 < filler->map.width)
		&& filler->map.board[p->y][p->x + 1] == '.')
		return (1);
	if ((p->x - 1 > 0) && filler->map.board[p->y][p->x - 1] == '.')
		return (1);
	return (0);
}

int	check_overflow(t_filler *filler, int x, int y)
{
	if (y < 0)
		return (0);
	if (x < 0)
		return (0);
	if (y >= filler->map.height)
		return (0);
	if (x >= filler->map.width)
		return (0);
	return (1);
}

int	is_good(t_filler *filler, t_point *p, t_point *t)
{
	int i;
	int x1;
	int y1;

	i = 0;
	while (i < filler->piece.cnt)
	{
		y1 = (filler->piece.p[i].y - p->y + t->y);
		x1 = (filler->piece.p[i].x - p->x + t->x);
		if (i == p->i)
			i++;
		else
		{
			if (!check_overflow(filler, x1, y1))
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
	t_point p;

	p.i = 0;
	while (p.i < filler->piece.cnt)
	{
		p.x = filler->piece.p[p.i].x;
		p.y = filler->piece.p[p.i].y;
		filler->piece.p[p.i].good = is_good(filler, &p, tracker);
		p.i++;
	}
	return (check_good(filler));
}
